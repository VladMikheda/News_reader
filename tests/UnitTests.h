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
private:
    std::string programName = "program name";
    std::string urlSting = "https://www.theregister.co.uk/headlines.atom";
//    char *argumentFeedList = "-f";
//    char *argumentCertificateFile = "-c";
//    char *argumentCertificatePath = "-C";
//    char *argumentTime = "-T";
//    char *argumentAuthor = "-a";
//    char *argumentURL = "-u";

//    const char arguments1[countArguments1][maxString] = {"program name"};
//    const char arguments2[countArguments2][maxString] = {"program name","https://en.wikipedia.org/w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom"};
//    const char arguments3[countArguments3][maxString] = {"program name","https://en.wikipedia.org:4333/w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom"};
//    const char arguments4[countArguments4][maxString] = {"program name","-f","/home/goofy/study/ISA/ISA/tests/feedfiletest"};
//    const char arguments5[countArguments5][maxString] = {"program name","-f"};
//    const char arguments6[countArguments6][maxString] = {"program name","https://en.wikipedia.org/w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom","-f","/home/goofy/study/ISA/ISA/tests/feedfiletest"};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-C",};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-c"};
//    const char arguments7[countArguments1][maxString] = {"program name","-C"};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-C","/etc/ssl/certs"};
//    const char arguments8[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-c","SecureTrust_CA.pem"};
//    const char arguments9[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-C","/etc/ssl/certs","-c","SecureTrust_CA.pem"};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-T"};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-a"};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-u"};
//    const char arguments7[countArguments1][maxString] = {"program name","https://www.theregister.co.uk/headlines.atom","-C","/etc/ssl/certs","-c","SecureTrust_CA.pem","-T","-a","-u"};
public:
    void testArgumentParser();
    void testURLParser();
    void testConnect();
    void XMLParser();
};


#endif //ISA_UNITTESTS_H
