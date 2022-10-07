#ifndef ISA_CONNECT_H
#define ISA_CONNECT_H

# include  "openssl/bio.h"
# include  "openssl/ssl.h"
# include  "openssl/err.h"




class Connect {
public:
    void initialization();
    void initializationSslConnect();

    void addDefaultSslCertificate();
    void addSslCertificate();
    void addSslCertificateDir();

    void settingBio();

    void sslConnect();
    void sendRequest();
    void readResponse();

    void closeConnect();


private:
    BIO* bio = nullptr;
    SSL* ssl = nullptr;

};


#endif //ISA_CONNECT_H
