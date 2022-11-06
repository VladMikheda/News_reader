/**
 * Project: Čtečka novinek ve formátu Atom a RSS s podporou TLS (Tests)
 *
 * File:     test.cpp
 * Subject:  ISA 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

#include "UnitTests.h"

/**
 * Main file for running unit tests
 * @return
 */
int main(){
    UnitTests unitTests;
    unitTests.testAll();
    return 0;
}