

#ifndef ISA_URLPARSER_H
#define ISA_URLPARSER_H
#include "Error.h"
#include <regex>
#include <string>
class UrlParser {

private:
    u_int16_t port = 0;
    std::string url{0};
    std::string urlString{0};
    //todo ip ???
    const std::string regexUrl =  "^(http|https)://[a-zA-Z\\.0-9-]+(:[0-9]+.+|[^:]+)$";
public:
    bool checkUrl(const std::string& urlString);
    bool regexUrlCheck();
};


#endif //ISA_URLPARSER_H
