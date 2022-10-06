
#include "UrlParser.h"


UrlParser::~UrlParser(){
    delete stringPort;
    delete domainName;
    delete path;
    delete parameters;
    delete fragment;
}

void UrlParser::parse(const std::string& urlArgument) {

    if(!checkUrl(urlArgument)){
        //todo error
        std::cout << "ERROR not correct url" << std::endl;
    }

    std::smatch allParts;
    if(!std::regex_match(urlString, allParts, std::regex(regexUrl))){
        std::cout << "ERROR" << std::endl;
    }

    parseScheme(allParts[schemeNumber].str());

    domainName = new std::string(allParts[domainNameNumber].str());

    if(!allParts[portNumber].str().empty()){
        stringPort = new std::string (allParts[portNumber].str().substr(1));
    }

    parsePort();

    if(!allParts[patchNumber].str().empty()){
        path = new std::string (allParts[patchNumber].str());
    }

    if(!allParts[parametersNumber].str().empty()){
        parameters = new std::string (allParts[parametersNumber].str());
    }

    if(!allParts[fragmentNumber].str().empty()){
        fragment = new std::string (allParts[fragmentNumber].str());
    }

}

bool UrlParser::checkUrl(const std::string& urlArgument) {

    const u_int64_t lastCharUrlString = urlArgument.length() - 1;
    if(urlArgument.c_str()[0] == '\'' && urlArgument.c_str()[lastCharUrlString] == '\''){
        urlString = urlArgument.substr(1,lastCharUrlString - 1);
//        std::cout << urlString <<  std::endl;
    }else{
        return false;
    }

    return true;
}


void UrlParser::parseScheme(const std::string& scheme) {
    if(scheme == HTTP){
        httpScheme = true;
    }else if(scheme == HTTPS){
        httpsScheme = true;
    }

//    std::cout << scheme << std::endl;
}

void UrlParser::parsePort() {

    if(stringPort){
        try{
            port = stoi(*stringPort, nullptr,10);
        }catch(std::exception const& e){
            //todo error
            std::cout << "ERROR port is not correct" << std::endl;
        }

        if(port > 65535 || port < 1){
            //todo error
            std::cout << "ERROR port is not correct" << std::endl;
        }
    }else{
        if(httpScheme){
            port = 80;
            stringPort = new std::string("80");
        }else if(httpsScheme){
            port = 443;
            stringPort = new std::string("443");
        }else{
            //todo error
            std::cout << "ERROR port is not exist";
        }
    }

}

int UrlParser::getPort() const {
    return port;
}

std::string* UrlParser::getStringPort() const {
    return stringPort;
}

std::string* UrlParser::getDomainName() const{
    return domainName;
}

std::string* UrlParser::getPath() const{
    return path;
}

std::string* UrlParser::getParameters() const {
    return parameters;
}

bool UrlParser::getHttpScheme() const {
    return httpScheme;
}

bool UrlParser::getHttpsScheme() const{
    return httpsScheme;
}

std::string *UrlParser::getFragment() const {
    return fragment;
}


