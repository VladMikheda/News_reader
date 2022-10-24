/**
 * Project: Čtečka novinek ve formátu Atom a RSS s podporou TLS
 *
 * File:     Error.cpp
 * Subject:  ISA 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

#include "Error.h"

/**
 * Print error
 * @param errorNumber
 * @param ex whether the program should end after writing out the error
 */
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
        case ERROR_URL_INVALID:
            errorMessage = "The specified url address is incorrect";
            break;
        case ERROR_PORT_INVALID:
            errorMessage = "The specified port is invalid";
            break;
        case ERROR_NOT_OPEN_XML_DOC:
            errorMessage = "Unable to open XML";
            break;
        case ERROR_NOT_EXIST_ROOT_ELEMENT:
            errorMessage = "The main root of the XML document was not put on";
            break;
        case ERROR_NOT_SUPPORTED_FORMAT:
            errorMessage = "The XML file is in a format that is not supported by";
            break;
        case ERROR_NOT_SUPPORTED_RSS_VERSION:
            errorMessage = "This version of RSS is not supported";
            break;
        case ERROR_NOT_CORRECT_RESPONSE:
            errorMessage = "The response code from the server is not successful";
            break;
        case ERROR_RESPONSE_HAS_NO_BODY:
            errorMessage = "The response from the server does not contain a body";
            break;
        case ERROR_NOT_OPEN_FILE:
            errorMessage = "Unable to open feed-file";
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

/**
 * Print message on std error
 * @param message text message
 */
void Error::printMessage(std::string message) {
    std::cerr << message << std::endl;
}
