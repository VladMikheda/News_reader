#include "ParseArguments.h"

void ParseArguments::checkArguments(int argc, char** argv){

    for (int i = 1; i < argc; i++){
        //parse argument to string
        std::string argument = searchArgument(argv[i]);

        if(argument == CERTIFICATE_FILE){
            checkArgumentValue(argc, i);
            certificateFileGiven = true;
            certificateFilePath = argv[++i]; // path entry for the certificate
            //todo path check

        }else if(argument == CERTIFICATE_DIRECTORY){
            checkArgumentValue(argc, i);
            certificateDirectoryGiven = true;
            certificateDirectoryPath = argv[++i];
        }else if(argument == FEED_FILE){
            if(urlGiven){
                Error::errorPrint(Error::ERROR_URL_OR_FEED_FILE);
            }
            checkArgumentValue(argc,i);
            feedFileGiven = true;
            feedFilePath = argv[++i];
        }else if(argument == TIME_CHANGE){
            timeChangeGiven = true;
        }else if(argument == NAME_AUTHOR){
            nameAuthorGiven = true;
        }else if(argument == ASSOCIATED_URL){
            associatedUrlGiven = true;
        }
        else{
            if(feedFileGiven){
                Error::errorPrint(Error::ERROR_URL_OR_FEED_FILE);
            }

            checkArgumentValue(argc,i);
            urlGiven = true;
            url = argv[i];
        }

    }

    if(!urlGiven && !feedFileGiven){
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

//void ParseArguments::checkUrl() {
//
//    UrlParser urlParser;
//    urlParser.parse(url);
//}

/// ______

bool ParseArguments::getTimeChangeGiven() const {
    return timeChangeGiven;
}

bool ParseArguments::getNameAuthorGiven() const {
    return nameAuthorGiven;
}

bool ParseArguments::getAssociatedUrlGiven() const {
    return associatedUrlGiven;
}

bool ParseArguments::getFeedFileGiven() const {
    return feedFileGiven;
}

bool ParseArguments::getUrlGiven() const {
    return urlGiven;
}

bool ParseArguments::getCertificateFileGiven() const {
    return certificateFileGiven;
}

bool ParseArguments::getCertificateDirectoryGiven() const {
    return certificateDirectoryGiven;
}

std::string ParseArguments::getUrl() const {
    return url;
}

std::string ParseArguments::getFeedFilePath() const {
    return feedFilePath;
}

std::string ParseArguments::getCertificateFilePath() const {
    return certificateFilePath;
}

std::string ParseArguments::getCertificateDirectoryPath() const {
    return certificateDirectoryPath;
}





//todo add check repeat given arguments