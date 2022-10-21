
#include "XMLParser.h"

bool XMLParser::parse(const std::string& xmlString) {

    doc = xmlParseDoc((xmlChar*)xmlString.c_str());
    if(!doc){
        //todo error
        std::cout << "Error not open XNL string" << std::endl;
    }

    rootElement = xmlDocGetRootElement(doc);
    if(!rootElement){
        std::cout << "Error not exist root element" << std::endl;
    }
    checkFormat();
    if(rss){
        parseInformationRSS();
    }else if(atom){
        parseFeedAtom();
    }else{
        return false;
    }

    return true;
}

void XMLParser::checkFormat() {
        if(!xmlStrcmp(rootElement->name, (const xmlChar*)"rss")){
            if(!xmlStrcmp(rootElement->properties->children->content, (const xmlChar*)"2.0")){
                rss = true;
            }else{
                //todo error
                std::cout << "1 not rss / atom" << std::endl;
            }
        }else if(!xmlStrcmp(rootElement->name, (const xmlChar*)"feed")){
            atom = true;
        }else{
            //todo error
            std::cout << "not rss / atom" << std::endl;
        }
}

void XMLParser::parseFeedAtom() {
    for( xmlNode *mainNode = rootElement->children; mainNode; mainNode = mainNode->next){

        if(!xmlStrcmp(mainNode->name, (const xmlChar*)"title")) {
            printMainTitle(xmlNodeGetContent(mainNode));
        }

        if(!xmlStrcmp(mainNode->name, (const xmlChar*)"entry")) {
            parseRecordsAtom(mainNode);
        }


    }

}
void XMLParser::parseRecordsAtom(xmlNode* entryNode) {
    xmlChar *elements[ALL_ITEM_ELEMENT]{nullptr,nullptr,nullptr,nullptr};

    for(xmlNode *itemNode = entryNode->children; itemNode; itemNode = itemNode->next) {
        if (!xmlStrcmp(itemNode->name, (const xmlChar *) "title")) {
            elements[TITLE] = xmlNodeGetContent(itemNode);
        }
        else if (url && (!xmlStrcmp(itemNode->name, (const xmlChar *) "link"))) {
            parseLinkAtom(itemNode, elements);
        }
        else if (author && (!xmlStrcmp(itemNode->name, (const xmlChar *) "author"))) {
            parseAuthorAtom(itemNode,elements);
        }
        else if (time && (!xmlStrcmp(itemNode->name, (const xmlChar *) "updated"))) {
            elements[TIME] = xmlNodeGetContent(itemNode);
        }
    }
    printRecordInformation(elements);
}


void XMLParser::parseLinkAtom(xmlNode *itemNode, xmlChar **elements) {
    for(_xmlAttr *linkProperties = itemNode->properties; linkProperties; linkProperties = linkProperties->next) {
        if (!xmlStrcmp(linkProperties->name, (const xmlChar *) "href")){
            elements[LINK] = xmlNodeGetContent(linkProperties->children);
        }
    }
}

void XMLParser::parseAuthorAtom(xmlNode *itemNode, xmlChar **elements) {
    for(xmlNode *nameNode = itemNode->children; nameNode; nameNode = nameNode->next){
        if (!xmlStrcmp(nameNode->name, (const xmlChar *) "name")){
            elements[AUTHOR_NAME] = xmlNodeGetContent(nameNode);
        }
        else if (!xmlStrcmp(nameNode->name, (const xmlChar *) "email")){
            elements[AUTHOR] = xmlNodeGetContent(nameNode);
        }
    }
}


void XMLParser::parseInformationRSS() {

    for( xmlNode *mainNode = rootElement->children; mainNode; mainNode = mainNode->next){

        if(!xmlStrcmp(mainNode->name, (const xmlChar*)"channel")) {
            parseChannelRSS(mainNode);
        }

    }
}

void XMLParser::parseChannelRSS(xmlNode* mainNode ) {
    for(xmlNode *channelNode = mainNode->children; channelNode; channelNode = channelNode->next){

        if(!xmlStrcmp(channelNode->name, (const xmlChar*)"title")){
            printMainTitle(xmlNodeGetContent(channelNode));
        }

        else if(!xmlStrcmp(channelNode->name, (const xmlChar*)"item")){
            parseRecordRSS(channelNode);
        }

    }
}


void XMLParser::parseRecordRSS(xmlNode* channelNode) {
    xmlChar *elements[ALL_ITEM_ELEMENT]{nullptr,nullptr,nullptr,nullptr};

    for(xmlNode *itemNode = channelNode->children; itemNode; itemNode = itemNode->next) {
        if (!xmlStrcmp(itemNode->name, (const xmlChar *) "title")) {
            elements[TITLE] = xmlNodeGetContent(itemNode);
        }
        else if (url && (!xmlStrcmp(itemNode->name, (const xmlChar *) "link"))) {
            elements[LINK] = xmlNodeGetContent(itemNode);
        }
        else if (author && (!xmlStrcmp(itemNode->name, (const xmlChar *) "author"))) {
            elements[AUTHOR] = xmlNodeGetContent(itemNode);
        }
        else if (time && (!xmlStrcmp(itemNode->name, (const xmlChar *) "pubDate"))) {
            elements[TIME] = xmlNodeGetContent(itemNode);
        }

    }
    printRecordInformation(elements);
}

void XMLParser::printRecordInformation(xmlChar **elements) {

    if(elements[TITLE]){
        if(!firstItem && (url || author || time)){
            std::cout << "\n";
        }
        std::cout << elements[TITLE] << std::endl;
    }else{
        if(elements[LINK] || (elements[AUTHOR] || elements[AUTHOR_NAME]) || elements[TIME]){
            if(!firstItem){
                std::cout << "\n";
            }
            std::cout << "----" << std::endl;
        }
    }

    if(elements[LINK]){
        std::cout << "URL: " << elements[LINK] << std::endl;
    }

    if(elements[TIME]){
        if(atom){
            std::cout << "Aktualizace: " << elements[TIME] << std::endl;
        }else{
            std::cout << "Zveřejněno: " << elements[TIME] << std::endl;
        }
    }

    if(elements[AUTHOR] || elements[AUTHOR_NAME]){

        std::cout << "Autor: ";
        if(elements[AUTHOR_NAME]){
            std::cout << elements[AUTHOR_NAME];
            if(elements[AUTHOR]){
                std::cout << " (" << elements[AUTHOR] << ")" << std::endl;
            }
        }else if(elements[AUTHOR]){
            std::cout << elements[AUTHOR] << std::endl;
        }

    }

    firstItem = false;

}

void XMLParser::printMainTitle(xmlChar* mainTitle) {
    if(!firstMainTitle){
        std::cout << "\n";
    }
    std::cout << "*** " << mainTitle << " ***" << std::endl;
    firstItem = true;
    firstMainTitle = false;
}




void XMLParser::setArguments(bool url, bool author, bool time) {
    this->url = url;
    this->author = author;
    this->time = time;
}

void XMLParser::reset() {
    this->url = false;
    this->author = false;
    this->time = false;

    atom = false;
    rss  = false;
    firstItem = false;

    xmlFreeDoc(doc);
    xmlCleanupParser();
    rootElement = nullptr;
    doc = nullptr;
}





