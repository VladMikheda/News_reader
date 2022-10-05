
#include "UrlParser.h"


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
