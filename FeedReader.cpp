#include "FeedReader.h"


void FeedReader::read(int argc, char **argv) {

    ParseArguments parseArguments = ParseArguments();
    parseArguments.checkArguments(argc,argv);

    if(parseArguments.getFeedFileGiven()){
        //todo parse file and add all url to list

    }else{
        urlList.push_back(parseArguments.getUrl());
    }

    UrlParser urlParser;
    for(const std::string& urlString : urlList){
        urlParser.parse(urlString);

    }

}
