#include "Error.h"

//void Error::errorPrint(int errorNumber, const std::string& errorMessage) {
//
//    std::cout << "ERROR: " + std::to_string(errorNumber) << std::endl;
//    std::cout << errorMessage << std::endl;
//}


void Error::errorPrint(int errorNumber, bool ex) {
    std::string errorMessage{0};
    std::cerr << "ERROR: " ;

    switch (errorNumber) {
        case ERROR_ARGUMENT_NOT_EXIST:
            errorMessage = "The given argument does not exist";
            break;
        case ERROR_ARGUMENT_NOT_VALUE:
            errorMessage = "The argument must be followed by the value of the argument";
            break;
        case ERROR_URL_OR_FEED_FILE:
            errorMessage = "Either URL or feed file must be specified";
            break;
        case ERROR_FAIL_DEFAULT_CERTIFICATE:
            errorMessage = "Default certificate issue";
            break;
        case ERROR_FAIL_CERTIFICATE_FILE:
            errorMessage = "Certificate file problem";
            break;
        case ERROR_FAIL_CERTIFICATE_DIR:
            errorMessage = "Problem with certificate directories";
            break;
        case ERROR_FAIL_OPEN_SECURE_CONNECT:
            errorMessage = "Failed to open ssl connection";
            break;
        case ERROR_FAIL_OPEN_CONNECT:
            errorMessage = "Failed to open connection";
            break;
        case ERROR_FAIL_CREATE_BIO:
            errorMessage = "Problem with creating BIO object";
            break;
        case ERROR_CERTIFICATE_INVALID:
            errorMessage = "The certificate being used is invalid";
            break;
        case ERROR_SSL_CONNECTION_FAIL:
            errorMessage = "Connection fail";
            break;
        case ERROR_SEND_REQUEST:
            errorMessage = "Request sending error";
            break;
        case ERROR_READ_BIO:
            errorMessage = "Failed to read response";
            break;
        case ERROR_ARGUMENT_REPEAT:
            errorMessage = "Using duplicate arguments";
            break;
        default:
            break;
    }

    std::cerr << errorMessage << std::endl;
    if(ex){
        std::exit(errorNumber);
    }
    //todo help
}
