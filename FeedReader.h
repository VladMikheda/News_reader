
#ifndef ISA_FEEDREADER_H
#define ISA_FEEDREADER_H
#include "ParseArguments.h"
#include "XMLParser.h"
#include <list>
#include <csignal>
#include "Connect.h"
#include <fstream>


class FeedReader {

public:
    std::list<std::string> urlList;

    void read(int argc, char** argv);
private:
    const std::string regexComment = "(^\\s*#.*$)|(^\\s*$)";


    std::string domainNamePort{0};
    std::string request{0};
    void generateDomainNamePort(const std::string& domainName, const std::string& port);
    void generateRequest(UrlParser &urlParser);
    bool getCertificate(ParseArguments &parseArguments, Connect &connect);
    void readFile(const std::string *filePath);


};


#endif //ISA_FEEDREADER_H
