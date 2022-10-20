#ifndef ISA_XMLPARSER_H
#define ISA_XMLPARSER_H

#include "Error.h"
#include <libxml/parser.h>
#include <string>

#define ALL_ITEM_ELEMENT 4
class XMLParser {

private:

    const u_int8_t TITLE = 0;
    const u_int8_t LINK = 1;
    const u_int8_t AUTHOR = 2;
    const u_int8_t TIME = 3;


    bool atom = false;
    bool rss  = false;
    bool time = false;
    bool url = false;
    bool author = false;

    bool firstItem = false;

    xmlNode *rootElement = nullptr;

    void checkFormat();
    void parseFeedAtom();
    void parseRecordsAtom(xmlNode* entryNode );
    void parseInformationRSS();
    void parseChannelRSS(xmlNode* mainNode);
    void parseRecordRSS(xmlNode* channelNode);
    void printMainTitle();
    void printRecordInformation(xmlChar **elements);

public:
    XMLParser(bool url, bool author, bool time);
    bool parse(const std::string& xmlString);
};


#endif //ISA_XMLPARSER_H
