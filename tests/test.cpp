/**
 * Project: Čtečka novinek ve formátu Atom a RSS s podporou TLS
 *
 * File:     test.cpp
 * Subject:  ISA 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

#include <iostream>
#include "UnitTests.h"

int main(){

//    std::cout << "Hello World!" << std::endl;
    UnitTests unitTests;
    unitTests.testArgumentParser();
    return 0;
}