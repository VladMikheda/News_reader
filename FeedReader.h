
#ifndef ISA_FEEDREADER_H
#define ISA_FEEDREADER_H
#include "ParseArguments.h"
#include <list>

class FeedReader {

public:
    std::list<std::string> urlList;

    void read(int argc, char** argv);


};


#endif //ISA_FEEDREADER_H
