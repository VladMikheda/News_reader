//
// Created by goofy on 06.11.22.
//

#ifndef ISA_TESTXMLPARSER_H
#define ISA_TESTXMLPARSER_H


#include <string>

class TestXMLParser {

private:
     std::string normalRSS = "";
     std::string RSSNotMainTitle = "";
     std::string RSSNotTitle = "";
     std::string RSSNotAuthor = "";
     std::string RSSNotUpdate = "";
     std::string RSSNotURL = "";
     std::string normalAtom = "";
     std::string AtomNotMainTitle = "";
     std::string AtomNotTitle = "";
     std::string AtomNotAuthor = "";
     std::string AtomNotUpdate = "";
     std::string AtomNotURL = "";

public:

    void RSSNormal();

};


#endif //ISA_TESTXMLPARSER_H
