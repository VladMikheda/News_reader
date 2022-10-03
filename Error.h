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
    };

    static void errorPrint(int errorNumber);

};


#endif //ISA_ERROR_H
