
#include "XMLParser.h"

void XMLParser::parse(const std::string& xmlString) {
    xmlDoc *doc = nullptr;
    doc = xmlParseDoc((xmlChar*)xmlString.c_str());
    if(!doc){
        //todo error
        std::cout << "Error not open XNL string" << std::endl;
    }

    rootElement = xmlDocGetRootElement(doc);
    if(!rootElement){
        std::cout << "Error not exist root element" << std::endl;
    }

    std::cout << rootElement->ns->href << std::endl;

}

void XMLParser::checkFormat() {

}

void XMLParser::parseInformation() {

}

void XMLParser::parseMainInformationAtom() {

}

void XMLParser::parseRecordsAtom() {

}

void XMLParser::parseMainInformationRSS() {

}

void XMLParser::parseRecordRSS() {

}
