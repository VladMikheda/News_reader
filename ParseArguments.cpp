/**
 * Project: Čtečka novinek ve formátu Atom a RSS s podporou TLS
 *
 * File:     ParseArguments.cpp
 * Subject:  ISA 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

#include "ParseArguments.h"

// Class destructor
ParseArguments::~ParseArguments(){
    delete url;
    delete feedFilePath;
    delete certificateFilePath;
    delete certificateDirectoryPath;
}

//The method of deallocation the memory of variables
// Called on errors
void ParseArguments::cleanAll() {
    delete url;
    delete feedFilePath;
    delete certificateFilePath;
    delete certificateDirectoryPath;
    url = nullptr;
    feedFilePath = nullptr;
    certificateFilePath= nullptr;
    certificateDirectoryPath= nullptr;
}


//The main method in the class runs the argument check
void ParseArguments::checkArguments(int argc, char** argv){

    for (int i = 1; i < argc; i++){

        //parse argument to string
        std::string argument = searchArgument(argv[i]);

        //checking parsed arguments for correctness
        if(argument == CERTIFICATE_FILE){

            if(certificateFilePath){
                cleanAll();
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
            }

            checkArgumentValue(argc, i);
            certificateFilePath = new std::string(argv[++i]); // path entry for the certificate

        }else if(argument == CERTIFICATE_DIRECTORY){

            if(certificateDirectoryPath){
                cleanAll();
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
            }

            checkArgumentValue(argc, i);
            certificateDirectoryPath = new std::string(argv[++i]);

        }else if(argument == FEED_FILE){

            if(feedFilePath){
                cleanAll();
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
            }

            checkArgumentValue(argc,i);
            feedFilePath = new std::string(argv[++i]);

        }else if(argument == TIME_CHANGE){

            if(time) {
                cleanAll();
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
            }
            time = true;

        }else if(argument == NAME_AUTHOR){

            if(author) {
                cleanAll();
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
            }
            author = true;

        }else if(argument == ASSOCIATED_URL){

            if(associateUrl) {
                cleanAll();Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
                cleanAll();}
            associateUrl = true;

        }else{
            if(url) {
                cleanAll();
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT);
            }
            url = new std::string(argv[i]);
        }

    }

    if((!url && !feedFilePath) || (url && feedFilePath)){
        cleanAll();
        Error::errorPrint(Error::ERROR_URL_OR_FEED_FILE);
    }

}

//Preparation of arguments for verification
//Separation of the sign '-'
std::string ParseArguments::searchArgument(char *arg) {
    return (arg[0] == '-') ? std::string {&arg[1]} : std::string(arg);
}


//checking if a value follows an argument
void ParseArguments::checkArgumentValue(int argc, int number) {
    if(number + 1 >=  argc){
        cleanAll();
        Error::errorPrint(Error::ERROR_ARGUMENT_NOT_VALUE);
    }
}


bool ParseArguments::isTime() const {
    return time;
}

bool ParseArguments::isAuthor() const {
    return author;
}

bool ParseArguments::isAssociateUrl() const {
    return associateUrl;
}

std::string* ParseArguments::getUrl() const {
    return url;
}

std::string* ParseArguments::getFeedFilePath() const {
    return feedFilePath;
}

std::string* ParseArguments::getCertificateFilePath() const {
    return certificateFilePath;
}

std::string* ParseArguments::getCertificateDirectoryPath() const {
    return certificateDirectoryPath;
}

