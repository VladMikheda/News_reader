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
    UnitTests unitTests;
    unitTests.testAll();
//    unitTests.testArgumentParser();
//    unitTests.testURLParser();
    return 0;
}