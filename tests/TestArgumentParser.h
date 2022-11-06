
#ifndef ISA_TESTARGUMENTPARSER_H
#define ISA_TESTARGUMENTPARSER_H

#include <iostream>
#include "../ParseArguments.h"
#include <cassert>

class TestArgumentParser {

private:
    std::string programName = "program name";
    std::string urlSting = "https://www.theregister.co.uk/headlines.atom";
    std::string argumentFeedList = "-f";
    std::string feedFilePath = "/feedfiletest";
    std::string argumentCertificateFile = "-c";
    std::string argumentCertificateDir = "-C";
    std::string certificateDirPath = "/etc/ssl/certs";
    std::string certificateFilePath = "/etc/ssl/certs/SecureTrust_CA.pem";
    std::string argumentTime = "-T";
    std::string argumentAuthor = "-a";
    std::string argumentURL = "-u";
public:
    void emptyArguments();
    void URLArgument();
    void feedFileNoPathArgument();
    void feedFileArgument();
    void urlAndFeedFileArgument();
    void certificateDirNoPathArgument();
    void certificateDirArgument();
    void certificateFileNoPathArgument();
    void certificateFileArgument();
    void certificateDirAndFileArgument();
    void printTimeArgument();
    void printAuthorArgument();
    void printUrlArgument();
    void allNormalArguments();

};


#endif //ISA_TESTARGUMENTPARSER_H
