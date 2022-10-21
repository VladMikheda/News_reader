#include "ParseArguments.h"

ParseArguments::~ParseArguments(){
    delete url;
    delete feedFilePath;
    delete certificateFilePath;
    delete certificateDirectoryPath;
}


bool ParseArguments::checkArguments(int argc, char** argv){

    for (int i = 1; i < argc; i++){

        //parse argument to string
        std::string argument = searchArgument(argv[i]);

        if(argument == CERTIFICATE_FILE){

            if(certificateFilePath){
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            if(checkArgumentValue(argc, i)){
                return false;
            }
            certificateFilePath = new std::string(argv[++i]); // path entry for the certificate

        }else if(argument == CERTIFICATE_DIRECTORY){

            if(certificateDirectoryPath){
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            if(checkArgumentValue(argc, i)){
                return false;
            }
            certificateDirectoryPath = new std::string(argv[++i]);

        }else if(argument == FEED_FILE){

            if(feedFilePath){
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            checkArgumentValue(argc,i);
            feedFilePath = new std::string(argv[++i]);

        }else if(argument == TIME_CHANGE){

            if(time) {
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            time = true;

        }else if(argument == NAME_AUTHOR){

            if(author) {
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            author = true;

        }else if(argument == ASSOCIATED_URL){

            if(associateUrl) {
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            associateUrl = true;

        }else{

            if(url) {
                Error::errorPrint(Error::ERROR_ARGUMENT_REPEAT, false);
                return false;
            }

            url = new std::string(argv[i]);
        }

    }

    if((!url && !feedFilePath) || (url && feedFilePath)){
        Error::errorPrint(Error::ERROR_URL_OR_FEED_FILE, false);
        return false;
    }

    return true;
}

std::string ParseArguments::searchArgument(char *arg) {
    return (arg[0] == '-') ? std::string {&arg[1]} : std::string(arg);
}

bool ParseArguments::checkArgumentValue(int argc, int number) {
    if(number + 1 >=  argc){
        Error::errorPrint(Error::ERROR_ARGUMENT_NOT_VALUE, false);
        return false;
    }
    return true;
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