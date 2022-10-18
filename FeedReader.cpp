#include "FeedReader.h"



void FeedReader::read(int argc, char **argv) {

    ParseArguments parseArguments = ParseArguments();
    parseArguments.checkArguments(argc,argv);

    if(parseArguments.getFeedFilePath()){
        //todo parse file and add all url to list

    }else{
        urlList.push_back(*parseArguments.getUrl());
    }

    UrlParser urlParser;
    Connect connect;
    connect.initialization();
    for(const std::string& urlString : urlList){
        urlParser.parse(urlString);

        generateDomainNamePort(*urlParser.getDomainName(),*urlParser.getStringPort());
        generateRequest(urlParser);

        connect.initializationSslConnect();


        if(urlParser.getHttpsScheme()){

            if(!getCertificate(parseArguments,connect)){
                connect.closeConnect();
                continue;
            }

            connect.settingBio();

            if(!connect.isCertificateValid()){
                std::cout << "ERROR" << std::endl;
            }

            connect.sslConnect(domainNamePort);

            if(!connect.isCertificateValid()){
                std::cout << "ERROR" << std::endl;
            }

            connect.sendRequest(request);
        }

        int amountRead = 0;
        int amount = 0;
        char buffer[BUFFER_SIZE] = {'\0'};
        bool first = true;

        while(true){
            memset(buffer,'\0', BUFFER_SIZE);
            amountRead = connect.readResponse(buffer,BUFFER_SIZE);
            std::cout << buffer << std::endl;
            if(!first){
                amount += amountRead;
            }
            first = false;
            if(amountRead == 0){
                std::cout << amount << std::endl;
                break;
            }
        }
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

    request = "GET " + fullPath + " HTTP/1.1\r\n"
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
