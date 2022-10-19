#ifndef ISA_CONNECT_H
#define ISA_CONNECT_H

# include  "openssl/bio.h"
# include  "openssl/ssl.h"
# include  "openssl/err.h"
#include <string>
#include "Error.h"
#define BUFFER_SIZE 1024



class Connect {
public:
    void initialization();
    void initializationSslConnect();

    bool addDefaultSslCertificate();
    bool addSslCertificate(const std::string& certificatePath);
    bool addSslCertificateDir(const std::string& certificateDirPath);

    bool settingBio();
    bool unsecureConnect(const std::string& url);
    void sslConnect(const std::string& url);
    bool isCertificateValid();
    bool sendRequest(const std::string& request);
    bool readResponse(std::string &response);
    bool checkConnect();
    void closeConnect();


private:
    BIO* bio = nullptr;
    SSL* ssl = nullptr;
    SSL_CTX  *ctx = nullptr;
};


#endif //ISA_CONNECT_H
