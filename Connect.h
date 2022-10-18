#ifndef ISA_CONNECT_H
#define ISA_CONNECT_H

# include  "openssl/bio.h"
# include  "openssl/ssl.h"
# include  "openssl/err.h"
#include <string>
#include "Error.h"




class Connect {
public:
    void initialization();
    void initializationSslConnect();

    bool addDefaultSslCertificate();
    bool addSslCertificate(const std::string& certificatePath);
    bool addSslCertificateDir(const std::string& certificateDirPath);

    void settingBio();
    bool unsecureConnect(const std::string& url);
    bool sslConnect(const std::string& url);
    bool isCertificateValid();
    void sendRequest(const std::string& request);
    int readResponse(char* buf, int bufSize);

    void closeConnect();


private:
    BIO* bio = nullptr;
    SSL* ssl = nullptr;
    SSL_CTX  *ctx = nullptr;
};


#endif //ISA_CONNECT_H
