/**
 * Project: Čtečka novinek ve formátu Atom a RSS s podporou TLS
 *
 * File:     FeedReader.cpp
 * Subject:  ISA 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

#include "FeedReader.h"

void FeedReader::read(int argc, char **argv) {

    ParseArguments parseArguments;
    //call method to parse arguments
    parseArguments.checkArguments(argc,argv);

    //if the file is set, we read from the file and add all the URLs to the list
    // if not, add the specified url
    if(parseArguments.getFeedFilePath()){
        readFile(parseArguments.getFeedFilePath());
    }else{
        urlList.push_back(*parseArguments.getUrl());
    }

    UrlParser urlParser;
    Connect connect;
    connect.initialization();
    XMLParser xmlParser;
    for(const std::string& urlString : urlList){

        //url string parse -> domain, port...
        if(!urlParser.parse(urlString)){
            //todo out use url
            continue;
        }

        //concatenate domain name and port to get connection address
        generateDomainNamePort(*urlParser.getDomainName(),*urlParser.getStringPort());
        generateRequest(urlParser);


        if(urlParser.getHttpsScheme()){
            //initialize structure to hold the sll information
            connect.initializationSslConnect();

            if(!getCertificate(parseArguments,connect)){
                connect.closeConnect();
                continue;
            }

            if(!connect.settingBio()){
                //todo add error
                connect.closeConnect();
                continue;
            }

            connect.sslConnect(domainNamePort);
            if(!connect.checkConnect()){
                //todo add error
                connect.closeConnect();
                continue;
            }

            if(!connect.isCertificateValid()){
                //todo add error
                connect.closeConnect();
                continue;
            }

        }else if(urlParser.getHttpScheme()){
            if(!connect.unsecureConnect(domainNamePort)){
                //todo add error
                connect.closeConnect();
                continue;
            }
            if(!connect.checkConnect()){
                //todo add error
                connect.closeConnect();
                continue;
            }
        }


        if(!connect.sendRequest(request)){
            //todo add error
            connect.closeConnect();
            continue;
        }

        std::string response{0};
        if(!connect.readResponse(response)){
            //todo add error
            connect.closeConnect();
            continue;
        }

//        std::cout << response << std::endl;

//        std::cout << request << std::endl;

        std::string xmlString = response.substr(response.find("\r\n\r\n") + 4);
//        std::cout << xmlString << std::endl;
    ///////////
        xmlParser.setArguments(parseArguments.isAssociateUrl(), parseArguments.isAuthor(), parseArguments.isTime());
        if(!xmlParser.parse(xmlString)){
            continue;
        }

        connect.closeConnect();
        xmlParser.reset();
        urlParser.reset();
    }

}

void FeedReader::generateDomainNamePort(const std::string& domainName, const std::string& port) {
    domainNamePort = domainName + ":" + port;
}

void FeedReader::generateRequest(UrlParser &urlParser) {
    const std::string userAgent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36";
    std::string fullPath = "/";
    if(urlParser.getPath()){
        fullPath = *urlParser.getPath();
    }
    if(urlParser.getParameters()){
        fullPath += *urlParser.getParameters();
    }
    if(urlParser.getFragment()){
        fullPath += *urlParser.getFragment();
    }

    request = "GET " + fullPath + " HTTP/1.0\r\n"
              + "Host:" + *urlParser.getDomainName() + "\r\n"
              + "Connection:Close"+ "\r\n"
              + "User-Agent:" + userAgent + "\r\n\r\n";
}

bool FeedReader::getCertificate(ParseArguments &parseArguments, Connect &connect) {
    if(parseArguments.getCertificateFilePath()){
        return connect.addSslCertificate(*parseArguments.getCertificateFilePath());
    }else if(parseArguments.getCertificateDirectoryPath()){
        return connect.addSslCertificateDir(*parseArguments.getCertificateDirectoryPath());
    }else{
        return connect.addDefaultSslCertificate();
    }
}

void FeedReader::readFile(const std::string *filePath) {
    std::ifstream file (*filePath);
    if(!file){
        std::cout << "ERROR open file " + *filePath << std::endl;
    }

    std::string fileLine{0};
    while(!file.eof()){
        getline(file,fileLine);
        if(!std::regex_match(fileLine, std::regex(regexComment))){
            urlList.push_back(fileLine);
        }
    }
    file.close();
}


