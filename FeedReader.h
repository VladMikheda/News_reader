
#ifndef ISA_FEEDREADER_H
#define ISA_FEEDREADER_H
#include "ParseArguments.h"
#include <list>
#include <cstring>
#include <csignal>
#include "Connect.h"

class FeedReader {

public:
    std::list<std::string> urlList;

    void read(int argc, char** argv);
private:
    std::string domainNamePort{0};
    std::string request{0};
    void generateDomainNamePort(const std::string& domainName, const std::string& port);
    void generateRequest(UrlParser &urlParser);
    bool getCertificate(ParseArguments &parseArguments, Connect &connect);



};


#endif //ISA_FEEDREADER_H
