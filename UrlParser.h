

#ifndef ISA_URLPARSER_H
#define ISA_URLPARSER_H
#include "Error.h"
#include <regex>
#include <string>
class UrlParser {

private:
    const std::string HTTP = "http";
    const std::string HTTPS = "https";
    const std::string regexUrl =  "^(http|https)://[a-zA-Z\\.0-9-]+(:[0-9]+.+|[^:]+)$";

    int port = 0;
    bool httpScheme = false;
    bool httpsScheme = false;
    std::string stringPort{0};
    std::string url{0};
    std::string urlString{0};
    std::string domainName{0};
    std::string path{0};
    std::string parameters{0};

    bool parseScheme(u_int16_t& schemeLen);
    void parseDomainName();
    void parsePort();
    void parsePath(u_int16_t schemeLen);
    void parseParameters(u_int16_t schemeLen);
    bool checkUrl(const std::string& urlString);
    bool regexUrlCheck();


public:
    void parse(const std::string& urlArgument);
    int getPort() const;
    bool getHttpScheme() const;
    bool getHttpsScheme() const;
    std::string getDomainName() const;
    std::string getPath() const;
    std::string getParameters() const;
};


#endif //ISA_URLPARSER_H
