#ifndef ISA_UNITTESTS_H
#define ISA_UNITTESTS_H

#include "../ParseArguments.h"
#include "../XMLParser.h"
#include "../Connect.h"
#include <iostream>

//#define countArguments1 1
//#define countArguments2 2
//#define countArguments3 2
//#define countArguments4 3
//#define countArguments5 2
//#define countArguments6 4
//#define maxString 1000

class UnitTests {

public:
    void testArgumentParser();
    void testURLParser();
    void testConnect();
    void XMLParser();
    void testAll();
};


#endif //ISA_UNITTESTS_H
