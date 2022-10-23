/**
 * Project: Čtečka novinek ve formátu Atom a RSS s podporou TLS
 *
 * File:     UrlParser.cpp
 * Subject:  ISA 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

#include "UrlParser.h"

// Class destructor
UrlParser::~UrlParser(){
    delete stringPort;
    delete domainName;
    delete path;
    delete parameters;
    delete fragment;
}

bool UrlParser::parse(const std::string& urlArgument) {

    std::smatch allParts;
    if(!std::regex_match(urlArgument, allParts, std::regex(regexUrl))){
        Error::errorPrint(Error::ERROR_URL_INVALID, false);
        return false;
    }

    parseScheme(allParts[schemeNumber].str());

    domainName = new std::string(allParts[domainNameNumber].str());

    if(!allParts[portNumber].str().empty()){
        //todo : -> value
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

    return true;
}

void UrlParser::parseScheme(const std::string& scheme) {
    if(scheme == HTTP){
        httpScheme = true;
    }else if(scheme == HTTPS){
        httpsScheme = true;
    }
}

bool UrlParser::parsePort() {

    if(stringPort){
        try{
            port = stoi(*stringPort, nullptr,10);
        }catch(std::exception const& e){
            Error::errorPrint(Error::ERROR_PORT_INVALID, false);
            return false;
        }

        if(port > 65535 || port < 1){
            Error::errorPrint(Error::ERROR_PORT_INVALID, false);
            return false;
        }
    }else{
        if(httpScheme){
            port = 80;
            stringPort = new std::string("80");
        }else if(httpsScheme){
            port = 443;
            stringPort = new std::string("443");
        }
    }
}

void UrlParser::reset(){
    delete stringPort;
    delete domainName;
    delete path;
    delete parameters;
    delete fragment;

    stringPort = nullptr;
    domainName = nullptr;
    path = nullptr;
    parameters = nullptr;
    fragment = nullptr;

    httpScheme = false;
    httpsScheme = false;
    urlString = {0};
    port = 0;
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


