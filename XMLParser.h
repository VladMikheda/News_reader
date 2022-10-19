#ifndef ISA_XMLPARSER_H
#define ISA_XMLPARSER_H

#include "Error.h"
#include <libxml/parser.h>
#include <string>


class XMLParser {

private:
    bool atom = false;
    bool rss  = false;
    xmlNode *rootElement = nullptr;

    void checkFormat();
    void parseInformation();
    void parseMainInformationAtom();
    void parseRecordsAtom();
    void parseMainInformationRSS();
    void parseRecordRSS();
public:

    void parse(const std::string& xmlString);
};


#endif //ISA_XMLPARSER_H
