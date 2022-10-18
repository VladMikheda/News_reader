#include <iostream>
#include "Connect.h"


void Connect::initialization() {
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
}

void Connect::initializationSslConnect() {
    ctx = SSL_CTX_new(SSLv23_client_method());
}

bool Connect::addDefaultSslCertificate() {
    if(!SSL_CTX_set_default_verify_paths(ctx)){
        Error::errorPrint(Error::ERROR_FAIL_DEFAULT_CERTIFICATE, false);
        return false;
    }
    return true;
}

bool Connect::addSslCertificate(const std::string& certificatePath) {
    if(!SSL_CTX_load_verify_locations(ctx, certificatePath.c_str(), nullptr)){
        Error::errorPrint(Error::ERROR_FAIL_CERTIFICATE_FILE, false);
        return false;
    }
    return true;
}

bool Connect::addSslCertificateDir(const std::string& certificateDirPath) {
    if(!SSL_CTX_load_verify_locations(ctx, certificateDirPath.c_str(), nullptr)){
        Error::errorPrint(Error::ERROR_FAIL_CERTIFICATE_DIR, false);
        return false;
    }
    return true;
}

void Connect::settingBio() {
    bio = BIO_new_ssl_connect(ctx);
    BIO_get_ssl(bio, &ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
}
bool Connect::unsecureConnect(const std::string& url){
    bio = BIO_new_connect("url");
    if(bio == nullptr)
    {
        Error::errorPrint(Error::ERROR_FAIL_CREATE_BIO, false);
        return false;
    }

    if(BIO_do_connect(bio) <= 0)
    {
        Error::errorPrint(Error::ERROR_FAIL_OPEN_CONNECT, false);
        return false;
    }
    return true;
}
bool Connect::sslConnect(const std::string& url) {
    BIO_set_conn_hostname(bio, url.c_str());

    if(BIO_do_connect(bio) <= 0)
    {
        Error::errorPrint(Error::ERROR_FAIL_OPEN_SECURE_CONNECT, false);
        return false;
    }
    return true;
}

bool Connect::isCertificateValid() {
    if(SSL_get_verify_result(ssl) != X509_V_OK)
    {
        return false;
    }

    return true;
}

void Connect::sendRequest(const std::string& request) {
    if(BIO_write(bio, request.c_str(), request.length()) <= 0)
    {
        if(! BIO_should_retry(bio))
        {
            std::cout << "ERROR" << std::endl;
        }
        std::cout << "ERROR" << std::endl;
        //todo transfer to connect
    }
}

int Connect::readResponse(char* buf, int bufSize) {
    int x = BIO_read(bio, buf, bufSize);
    return x;
//    if(x == 0)
//    {
//        std::cout << "ERROR" << std::endl;
//    }
//    else if(x < 0)
//    {
//        if(! BIO_should_retry(bio))
//        {
//            std::cout << "ERROR" << std::endl;
//        }
//    }
}

void Connect::closeConnect() {
    if(bio){
        BIO_free_all(bio);
    }
    if(ctx){
        SSL_CTX_free(ctx);
    }
}
