
#include "XMLParser.h"

bool XMLParser::parse(const std::string& xmlString) {

    xmlDoc *doc = xmlParseDoc((xmlChar*)xmlString.c_str());
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
            //todo call print function
            std::cout << "****" << xmlNodeGetContent(mainNode) << "****" << std::endl;
            firstItem = true;
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
//            std::cout << xmlNodeGetContent(itemNode) << std::endl;
        }
        else if (!xmlStrcmp(itemNode->name, (const xmlChar *) "link")) {
            //todo method
//            elements[LINK] = xmlNodeGetContent(itemNode);
//            std::cout << xmlNodeGetContent(itemNode->properties->children) << std::endl;
        }
//        else if (!xmlStrcmp(itemNode->name, (const xmlChar *) "author")) {
            //todo method
//            elements[AUTHOR] = xmlNodeGetContent(itemNode);
////            std::cout << xmlNodeGetContent(itemNode) << std::endl;
//        }
        else if (!xmlStrcmp(itemNode->name, (const xmlChar *) "updated")) {
            elements[TIME] = xmlNodeGetContent(itemNode);
//            std::cout << xmlNodeGetContent(itemNode) << std::endl;
        }


    }
    printRecordInformation(elements);
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
            //todo call print function
            std::cout << "****" << xmlNodeGetContent(channelNode) << "****" << std::endl;
            firstItem = true;
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
//            std::cout << xmlNodeGetContent(itemNode) << std::endl;
        }
        else if (!xmlStrcmp(itemNode->name, (const xmlChar *) "link")) {
            elements[LINK] = xmlNodeGetContent(itemNode);
//            std::cout << xmlNodeGetContent(itemNode) << std::endl;
        }
        else if (!xmlStrcmp(itemNode->name, (const xmlChar *) "author")) {
            elements[AUTHOR] = xmlNodeGetContent(itemNode);
//            std::cout << xmlNodeGetContent(itemNode) << std::endl;
        }
        else if (!xmlStrcmp(itemNode->name, (const xmlChar *) "pubDate")) {
            elements[TIME] = xmlNodeGetContent(itemNode);
//            std::cout << xmlNodeGetContent(itemNode) << std::endl;
        }


    }
    printRecordInformation(elements);
}

void XMLParser::printRecordInformation(xmlChar **elements) {

    for(int i = 0; i < ALL_ITEM_ELEMENT; i++){
        if(elements[i]){
            if(i == TITLE){
                if(!firstItem){
                    std::cout << "\n";
                }
            }
            if(i == LINK && !url || i == AUTHOR && !author || i == TIME && !time){
                continue;
            }

            std::cout << elements[i] << std::endl;
        }else{
            if(i == 0 && ((url && elements[LINK])||(author && elements[AUTHOR])||(time && elements[TIME]) )){
                if(!firstItem){
                    std::cout << "\n";
                }
                std::cout << "----" << std::endl;
            }
        }
    }
    firstItem = false;

}

XMLParser::XMLParser(bool url, bool author, bool time) {
    this->url = url;
    this->author = author;
    this->time = time;
}


//    xmlNodeGetContent(rootElement->children->next->children)
//    std::cout <<rootElement->children->next->children->next->name << std::endl;
//    std::cout << xmlNodeGetContent(rootElement->children->next->children->next )<< std::endl;



