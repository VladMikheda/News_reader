#include "FeedReader.h"


void FeedReader::read(int argc, char **argv) {

    ParseArguments parseArguments = ParseArguments();
    parseArguments.checkArguments(argc,argv);

    if(parseArguments.getFeedFilePath()){
        //todo parse file and add all url to list

    }else{
        urlList.push_back(*parseArguments.getUrl());
    }

    UrlParser urlParser;
    for(const std::string& urlString : urlList){
        urlParser.parse(urlString);
        std::cout << *urlParser.getDomainName() << std::endl;
        std::cout << urlParser.getPort() << std::endl;
        std::cout << urlParser.getPath() << std::endl;
        std::cout << *urlParser.getParameters() << std::endl;
        std::cout << urlParser.getFragment()<< std::endl;

        //todo before go to pointer check it
    }

}
