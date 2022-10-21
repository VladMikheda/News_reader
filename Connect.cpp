#include <iostream>
#include <cstring>
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

bool Connect::settingBio() {
    bio = BIO_new_ssl_connect(ctx);
    if(!bio){
        Error::errorPrint(Error::ERROR_SSL_CONNECTION_FAIL, false);
        return false;
    }
    BIO_get_ssl(bio, &ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
    return true;
}
bool Connect::unsecureConnect(const std::string& url){
    bio = BIO_new_connect(url.c_str());
    if(bio == nullptr)
    {
        Error::errorPrint(Error::ERROR_FAIL_CREATE_BIO, false);
        return false;
    }
    return true;
}

bool Connect::checkConnect(){
    if(BIO_do_connect(bio) <= 0)
    {
        Error::errorPrint(Error::ERROR_FAIL_OPEN_CONNECT, false);
        return false;
    }
    return true;
}

void Connect::sslConnect(const std::string& url) {
    BIO_set_conn_hostname(bio, url.c_str());
}

bool Connect::isCertificateValid() {
    if(SSL_get_verify_result(ssl) != X509_V_OK)
    {
        Error::errorPrint(Error::ERROR_CERTIFICATE_INVALID, false);
        return false;
    }

    return true;
}

bool Connect::sendRequest(const std::string& request) {
    bool success = false;
    //todo count ????

    do{
        if(BIO_write(bio, request.c_str(), request.length()) > 0){
            success = true;
        }
    }while(!success && BIO_should_retry(bio));

    if(!success){
        Error::errorPrint(Error::ERROR_SEND_REQUEST, false);
    }
    return success;

}

bool Connect::readResponse(std::string &response) {
    bool success = false;
    bool error = false;

    int readBytes = 0;
    char buffer[BUFFER_SIZE] = {'\0'};

    do{
        readBytes = BIO_read(bio, buffer, BUFFER_SIZE - 1);

        if(readBytes > 0){
            buffer[readBytes] = '\0';
            response += buffer;
        }else if(readBytes < 0){
            success = false;
            if(!BIO_should_retry(bio)){
                error = true;
            }
        }else{
            success = true;
        }

    }while(!success && !error);

    if(error){
        Error::errorPrint(Error::ERROR_READ_BIO, false);
    }

    return success;
}

void Connect::closeConnect() {
    if(bio){
        BIO_free_all(bio);
    }
    bio = nullptr;
    if(ctx){
        SSL_CTX_free(ctx);
    }
    ctx = nullptr;
}
