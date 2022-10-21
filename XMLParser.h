#ifndef ISA_XMLPARSER_H
#define ISA_XMLPARSER_H

#include "Error.h"
#include <libxml/parser.h>
#include <string>

#define ALL_ITEM_ELEMENT 5
class XMLParser {

private:

    const u_int8_t TITLE = 0;
    const u_int8_t LINK = 1;
    const u_int8_t AUTHOR = 2;
    const u_int8_t TIME = 3;
    const u_int8_t AUTHOR_NAME = 4;


    bool atom = false;
    bool rss  = false;
    bool time = false;
    bool url = false;
    bool author = false;

    bool firstItem = false;
    bool firstMainTitle = true;

    xmlNode *rootElement = nullptr;
    xmlDoc *doc = nullptr;

    void checkFormat();
    void parseFeedAtom();
    void parseRecordsAtom(xmlNode* entryNode );
    void parseLinkAtom(xmlNode *itemNode, xmlChar **elements);
    void parseAuthorAtom(xmlNode *itemNode, xmlChar **elements);
    void parseInformationRSS();
    void parseChannelRSS(xmlNode* mainNode);
    void parseRecordRSS(xmlNode* channelNode);
    void printMainTitle(xmlChar* mainTitle);
    void printRecordInformation(xmlChar **elements);

public:
    void setArguments(bool url, bool author, bool time);
    void reset();
    bool parse(const std::string& xmlString);
};


#endif //ISA_XMLPARSER_H