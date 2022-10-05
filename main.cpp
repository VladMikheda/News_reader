
//#include <iostream>
//#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include "openssl/bio.h"

#include <netdb.h>
#include <arpa/inet.h>
using namespace std;

#include "FeedReader.h"

int main(int argc, char** argv) {

    FeedReader feedReader;
    feedReader.read(argc,argv);

//    ParseArguments parseArguments = ParseArguments();
//    parseArguments.checkArguments(argc,argv);

//    std::cout << "Hello World";


//    struct hostent *he = gethostbyname("www.theregister.com");
//    char *ip = inet_ntoa(*(struct in_addr *) he->h_addr_list[0]);
//    cout << ip;
//
//    struct sockaddr_in addr = {0};
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    addr.sin_family = AF_INET;
//    addr.sin_port = htons(80);
//    inet_pton(AF_INET, ip, &addr.sin_addr);
//
//    connect(sock,(struct sockaddr *) &addr, sizeof addr);
//    string message = "GET /software/headlines.atom HTTP/1.1\r\nHost:www.theregister.com\r\n\r\n";
//    write(sock, "GET /software/headlines.atom HTTP/1.1\r\nHost:www.theregister.com\r\n\r\n" ,message.size());
//    char buf[10000];
//    read(sock,buf, 10000);
//    cout << buf;
//    close(sock);



}