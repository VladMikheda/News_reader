//
// Created by goofy on 03.10.22.
//

#ifndef ISA_ERROR_H
#define ISA_ERROR_H
#include <iostream>

class Error {

public:
    enum {
        ERROR_ARGUMENT_NOT_EXIST =  100,
        ERROR_ARGUMENT_NOT_VALUE = 101,
        ERROR_URL_OR_FEED_FILE = 102,

        ERROR_FAIL_DEFAULT_CERTIFICATE = 110,
        ERROR_FAIL_CERTIFICATE_FILE = 111,
        ERROR_FAIL_CERTIFICATE_DIR = 112,
        ERROR_FAIL_OPEN_SECURE_CONNECT = 113,
        ERROR_FAIL_OPEN_CONNECT = 114,
        ERROR_FAIL_CREATE_BIO = 115,
        ERROR_SEND_REQUEST = 116,

        ERROR_CERTIFICATE_INVALID = 120,
        ERROR_SSL_CONNECTION_FAIL = 121,
        ERROR_READ_BIO = 122,
    };

    static void errorPrint(int errorNumber,  bool ex = true);

};


#endif //ISA_ERROR_H
