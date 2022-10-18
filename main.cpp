
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "openssl/bio.h"

#include <netdb.h>
#include <arpa/inet.h>
//using namespace std;

#include "FeedReader.h"

# include  "openssl/bio.h"
# include  "openssl/ssl.h"
# include  "openssl/err.h"

int main(int argc, char** argv) {

    FeedReader feedReader;
    feedReader.read(argc,argv);


//    //initialization
//    SSL_library_init();
//    SSL_load_error_strings();
//    ERR_load_BIO_strings();
//    OpenSSL_add_all_algorithms();
//
//    // new socket
//    BIO* bio = nullptr;
//
//    // initialization ssl connect
//    SSL_CTX  *ctx = nullptr;
//    ctx = SSL_CTX_new(SSLv23_client_method());
//    SSL  *ssl = nullptr;
//
//
//    //add SSL certificate  // + file // + path
//    SSL_CTX_set_default_verify_paths(ctx);
//
//    //sll setting
//    bio = BIO_new_ssl_connect(ctx);
//    BIO_get_ssl(bio, &ssl);
//    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
//
//    //SLL connect
//    BIO_set_conn_hostname(bio, "what-if.xkcd.com:443");
//
//    if(BIO_do_connect(bio) <= 0)
//    {
//        std::cout << "ERROR" << std::endl;
//    }
//
//    //check certificate valid
//    if(SSL_get_verify_result(ssl) != X509_V_OK)
//    {
//        std::cout << "ERROR SSL" << std::endl;
//    }
//
//
//    std::string message = "GET /feed.atom HTTP/1.1\r\nHost:what-if.xkcd.com\r\n\r\n";
//
//    if(BIO_write(bio, message.c_str(), message.length()) <= 0)
//    {
//        if(! BIO_should_retry(bio))
//        {
//            std::cout << "ERROR" << std::endl;
//        }
//        std::cout << "ERROR" << std::endl;
//    }
//
//    char buf[1000];
//    int x = BIO_read(bio, buf, 1000);
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
//
//    std::cout << buf << std::endl;
//
//    //reset
//    BIO_free_all(bio);
//    SSL_CTX_free(ctx);
/////__________________________________________________________________

//    ParseArguments parseArguments = ParseArguments();
//    parseArguments.checkArguments(argc,argv);

//    std::cout << "Hello World";


//    struct hostent *he = gethostbyname("en.wikipedia.org");
//    char *ip = inet_ntoa(*(struct in_addr *) he->h_addr_list[0]);
//    std::cout << ip << std::endl;
//
//    struct sockaddr_in addr = {0};
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(443);
//    inet_pton(AF_INET, "en.wikipedia.org", &addr.sin_addr);
//
//    std::cout << connect(sock,(struct sockaddr *) &addr, sizeof addr) << std::endl;
//    std::string message = "GET /w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom HTTP/1.1\r\nHost:en.wikipedia.org\r\n\r\n";
//    write(sock, "GET /w/api.php?hidebots=1&days=7&limit=50&hidewikidata=1&action=feedrecentchanges&feedformat=atom HTTP/1.1\r\nHost:en.wikipedia.org\r\n\r\n" ,message.size());
//    char buf[10000];
//    read(sock,buf, 10000);
//    std::cout << buf;
//    close(sock);



}