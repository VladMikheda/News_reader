#include "Error.h"

//void Error::errorPrint(int errorNumber, const std::string& errorMessage) {
//
//    std::cout << "ERROR: " + std::to_string(errorNumber) << std::endl;
//    std::cout << errorMessage << std::endl;
//}


void Error::errorPrint(int errorNumber) {
    std::string errorMessage{0};
    std::cout << "ERROR: " + std::to_string(errorNumber) << std::endl;
    if(errorNumber == ERROR_ARGUMENT_NOT_EXIST){
        errorMessage = "The given argument does not exist";
    }else if(errorNumber == ERROR_ARGUMENT_NOT_VALUE){
        errorMessage = "The argument must be followed by the value of the argument";
    }else if(errorNumber == ERROR_URL_OR_FEED_FILE){
        errorMessage = "Either URL or feed file must be specified";
    }
    std::cout << errorMessage << std::endl;
    std::exit(errorNumber);
    //todo help
}
