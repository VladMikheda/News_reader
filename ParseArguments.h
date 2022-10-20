
#ifndef ISA_PARSEARGUMENTS_H
#define ISA_PARSEARGUMENTS_H
#include "Error.h"
#include "UrlParser.h"
//using namespace std;


class ParseArguments {

private:
    //const arguments
    const std::string CERTIFICATE_FILE = "c";
    const std::string CERTIFICATE_DIRECTORY = "C";
    const std::string FEED_FILE = "f";
    const std::string TIME_CHANGE = "T";
    const std::string NAME_AUTHOR = "a";
    const std::string ASSOCIATED_URL = "u";

    // main arguments
    std::string* url = nullptr;
    std::string* feedFilePath = nullptr;
    std::string* certificateFilePath = nullptr;
    std::string* certificateDirectoryPath = nullptr;
    bool time = false;
    bool author = false;
    bool associateUrl = false;


public:
    ~ParseArguments();
    void checkArguments(int argc, char** argv);
    bool isTime() const;
    bool isAuthor() const;
    bool isAssociateUrl() const;
    std::string* getUrl() const;
    std::string* getFeedFilePath() const;
    std::string* getCertificateFilePath() const;
    std::string* getCertificateDirectoryPath() const;


private:
    std::string searchArgument(char* arg);
    void checkArgumentValue(int argc, int number);

};



#endif //ISA_PARSEARGUMENTS_H
