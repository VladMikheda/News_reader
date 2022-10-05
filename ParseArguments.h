
#ifndef ISA_PARSEARGUMENTS_H
#define ISA_PARSEARGUMENTS_H
#include "Error.h"
#include "UrlParser.h"
//using namespace std;


class ParseArguments {

private:

    std::string url{0};
    u_int16_t port; // specify by protocol value ???
    std::string feedFilePath{0};
    std::string certificateFilePath{0};
    std::string certificateDirectoryPath{0};
    bool timeChangeGiven = false;
    bool nameAuthorGiven = false;
    bool associatedUrlGiven = false;

    // bool variables to indicate whether an argument is given
    bool feedFileGiven = false;
    bool urlGiven = false;
    bool portGiven = false;
    bool certificateFileGiven = false;
    bool certificateDirectoryGiven = false;


    const std::string CERTIFICATE_FILE = "c";
    const std::string CERTIFICATE_DIRECTORY = "C";
    const std::string FEED_FILE = "f";
    const std::string TIME_CHANGE = "T";
    const std::string NAME_AUTHOR = "a";
    const std::string ASSOCIATED_URL = "u";

    const std::string regexUrl = "^(http|https)://[a-zA-Z\\.0-9-]+(:[0-9]+.+|[^:]+)$";


public:
    void checkArguments(int argc, char** argv);

private:
    std::string searchArgument(char* arg);
    void checkArgumentValue(int argc, int number);
    void checkUrl();

};



#endif //ISA_PARSEARGUMENTS_H
