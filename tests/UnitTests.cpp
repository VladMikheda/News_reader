#include <cassert>
#include "UnitTests.h"
#include "TestArgumentParser.h"

void UnitTests::testArgumentParser() {
    TestArgumentParser testArgumentParser;

    testArgumentParser.emptyArguments();
    testArgumentParser.URLArgument();
    testArgumentParser.feedFileNoPathArgument();
    testArgumentParser.feedFileArgument();
    testArgumentParser.urlAndFeedFileArgument();
    testArgumentParser.certificateDirNoPathArgument();
    testArgumentParser.certificateDirArgument();
    testArgumentParser.certificateFileNoPathArgument();
    testArgumentParser.certificateFileArgument();
    testArgumentParser.certificateDirAndFileArgument();
    testArgumentParser.printTimeArgument();
    testArgumentParser.printAuthorArgument();
    testArgumentParser.printUrlArgument();
    testArgumentParser.allNormalArguments();

    std::cout << "TEST:Tests ArgumentParser are SUCCESS" << std::endl;
}

void UnitTests::testURLParser() {

}

void UnitTests::testConnect() {

}

void UnitTests::XMLParser() {

}
