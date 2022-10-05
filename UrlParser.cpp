
#include "UrlParser.h"


void UrlParser::parse(const std::string& urlArgument) {

    u_int16_t schemeLen = 0;

    if(!checkUrl(urlArgument)){
        //todo error
        std::cout << "ERROR not correct url" << std::endl;
    }

    parseScheme(schemeLen);
    parseDomainName();
    parsePort();
    parsePath(schemeLen);
    parseParameters(schemeLen);

}

bool UrlParser::checkUrl(const std::string& urlArgument) {

    const u_int64_t lastCharUrlString = urlArgument.length() - 1;
    if(urlArgument.c_str()[0] == '\'' && urlArgument.c_str()[lastCharUrlString] == '\''){
        urlString = urlArgument.substr(1,lastCharUrlString - 1);
//        std::cout << urlString <<  std::endl;
    }else{
        return false;
    }

    if(!regexUrlCheck()){
        //todo error
        std::cout << "ERROR" << std::endl;
        return false;
    }

    return true;
}

bool UrlParser::regexUrlCheck(){
    //if url is not correct return false
    if(!std::regex_match(urlString, std::regex(regexUrl))){
        return false;
    }
    return true;
}

bool UrlParser::parseScheme(u_int16_t& schemeLen) {
    const std::string endSymbolsScheme = "://";
    u_int64_t endPositionScheme = urlString.find(endSymbolsScheme);
    std::string scheme = urlString.substr(0,endPositionScheme);

    if(scheme == HTTP){
        httpScheme = true;
        schemeLen = HTTP.length() + endSymbolsScheme.length();
    }else if(scheme == HTTPS){
        httpsScheme = true;
        schemeLen = HTTPS.length() + endSymbolsScheme.length();
    }else{
        return false;
    }
    return true;
//    std::cout << scheme << std::endl;
}
void UrlParser::parseDomainName() {
    const std::string endSymbolsScheme = "://";
    u_int64_t firstPosDomainName = urlString.find(endSymbolsScheme) + endSymbolsScheme.length();
    u_int64_t endPosDomainName = urlString.find('/',firstPosDomainName);
    if(endPosDomainName == std::string::npos){
        endPosDomainName = urlString.length() - 1;
    }
    u_int64_t lenDomainName = endPosDomainName - firstPosDomainName;
    domainName = urlString.substr(firstPosDomainName,lenDomainName);
    std::cout << domainName << std::endl;
}

void UrlParser::parsePort() {

    size_t firstPosPort = domainName.find(':');
    if(firstPosPort != std::string::npos){
        u_int64_t lenPort = domainName.length() - (firstPosPort + 1);
        stringPort = domainName.substr((firstPosPort + 1),lenPort);
        try{
            port = stoi(stringPort, nullptr,10);
        }catch(std::exception const& e){
            //todo error
            std::cout << "ERROR port is not correct" << std::endl;
        }

        if(port > 65535 || port < 1){
            //todo error
            std::cout << "ERROR port is not correct" << std::endl;
        }

//        std::cout << port;
    }else{
        if(httpScheme){
            port = 80;
        }else if(httpsScheme){
            port = 443;
        }else{
            //todo error
            std::cout << "ERROR port is not exist";
        }
    }

}

void UrlParser::parsePath(u_int16_t schemeLen) {
    size_t firstPosPath = urlString.find('/', schemeLen);
    if(firstPosPath != std::string::npos){
        size_t endPosPath = urlString.find('?', schemeLen);
        u_int64_t lenPatch = urlString.length() - (firstPosPath + 1);
        if(endPosPath != std::string::npos){
            lenPatch =  endPosPath - (firstPosPath + 1);
        }

        path = urlString.substr(firstPosPath + 1,lenPatch);

    }else{
        //todo просто его нету
    }
//    std::cout << path;
}

void UrlParser::parseParameters(u_int16_t schemeLen) {
    size_t firstPosParameters = urlString.find('?', schemeLen);
    if(firstPosParameters == std::string::npos){
        return;
    }
    u_int64_t lenParameters = urlString.length() - (firstPosParameters + 1);
    parameters = urlString.substr(firstPosParameters + 1, lenParameters);
//    std::cout << parameters;
}

int UrlParser::getPort() const {
    return port;
}

std::string UrlParser::getDomainName() const{
    return domainName;
}

std::string UrlParser::getPath() const{
    return path;
}

std::string UrlParser::getParameters() const {
    return parameters;
}

bool UrlParser::getHttpScheme() const {
    return httpScheme;
}

bool UrlParser::getHttpsScheme() const{
    return httpsScheme;
}

