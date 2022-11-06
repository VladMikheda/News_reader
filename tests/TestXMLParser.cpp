//
// Created by goofy on 06.11.22.
//

#include "TestXMLParser.h"
#include "../XMLParser.h"
#include <iostream>
void TestXMLParser::RSSNormal() {
   normalRSS = "";
   RSSNotMainTitle = "";
   RSSNotTitle = "";
   RSSNotAuthor = "";
   RSSNotUpdate = "";
   RSSNotURL = "";

   normalAtom = std::string("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n") +
                 "<feed xmlns=\"http://www.w3.org/2005/Atom\">\n" +
                "\n" +
                "  <title>Example Feed</title>\n" +
                "  <link href=\"http://example.org/\"/>\n" +
                "  <updated>2003-12-13T18:30:02Z</updated>\n" +
                "  <author>\n" +
                "    <name>John Doe</name>\n" +
                "  </author>\n" +
                "  <id>urn:uuid:60a76c80-d399-11d9-b93C-0003939e0af6</id>\n" +
                "\n" +
                "  <entry>\n" +
                "    <title>Atom-Powered Robots Run Amok</title>\n" +
                "    <link href=\"http://example.org/2003/12/13/atom03\"/>\n" +
                "    <id>urn:uuid:1225c695-cfb8-4ebb-aaaa-80da344efa6a</id>\n" +
                "    <updated>2003-12-13T18:30:02Z</updated>\n" +
                "    <summary>Some text.</summary>\n" +
                "  </entry>\n" +
                "\n" +
                "</feed>";
   AtomNotMainTitle = std::string("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n") +
                      "<feed xmlns=\"http://www.w3.org/2005/Atom\">\n" +
                      "\n" +
                      "  <link href=\"http://example.org/\"/>\n" +
                      "  <updated>2003-12-13T18:30:02Z</updated>\n" +
                      "  <author>\n" +
                      "    <name>John Doe</name>\n" +
                      "  </author>\n" +
                      "  <id>urn:uuid:60a76c80-d399-11d9-b93C-0003939e0af6</id>\n" +
                      "\n" +
                      "  <entry>\n" +
                      "    <title>Atom-Powered Robots Run Amok</title>\n" +
                      "    <link href=\"http://example.org/2003/12/13/atom03\"/>\n" +
                      "    <id>urn:uuid:1225c695-cfb8-4ebb-aaaa-80da344efa6a</id>\n" +
                      "    <updated>2003-12-13T18:30:02Z</updated>\n" +
                      "    <summary>Some text.</summary>\n" +
                      "  </entry>\n" +
                      "\n" +
                      "</feed>";
   AtomNotTitle = "";
   AtomNotAuthor = "";
   AtomNotUpdate = "";
   AtomNotURL = "";

   XMLParser xmlParser;
   xmlParser.setArguments(false, false, false);
   xmlParser.parse(AtomNotMainTitle);

}
