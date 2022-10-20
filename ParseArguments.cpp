#include "ParseArguments.h"

ParseArguments::~ParseArguments(){
    delete url;
    delete feedFilePath;
    delete certificateFilePath;
    delete certificateDirectoryPath;
}


void ParseArguments::checkArguments(int argc, char** argv){

    for (int i = 1; i < argc; i++){

        //parse argument to string
        std::string argument = searchArgument(argv[i]);

        if(argument == CERTIFICATE_FILE){
            checkArgumentValue(argc, i);
            certificateFilePath = new std::string(argv[++i]); // path entry for the certificate
            //todo path check
        }else if(argument == CERTIFICATE_DIRECTORY){
            checkArgumentValue(argc, i);
            certificateDirectoryPath = new std::string(argv[++i]);
        }else if(argument == FEED_FILE){
            checkArgumentValue(argc,i);
            feedFilePath = new std::string(argv[++i]);
        }else if(argument == TIME_CHANGE){
            time = true;
        }else if(argument == NAME_AUTHOR){
            author = true;
        }else if(argument == ASSOCIATED_URL){
            associateUrl = true;
        }
        else{
            url = new std::string(argv[i]);
        }

    }

    if((!url && !feedFilePath) || (url && feedFilePath)){
        Error::errorPrint(Error::ERROR_URL_OR_FEED_FILE);
    }


}

std::string ParseArguments::searchArgument(char *arg) {
    return (arg[0] == '-') ? std::string {&arg[1]} : std::string(arg);
}

void ParseArguments::checkArgumentValue(int argc, int number) {
    if(number + 1 >=  argc){
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





//todo add check repeat given arguments