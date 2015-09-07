#ifndef HTMLNODE_H
#define HTMLNODE_H
#include "Parser/programcodenode.h"
#include "helper.h"

class HtmlNode : public ProgramCodeNode
{
public:
    string HTML;
    HtmlNode(string html);

    // ProgramCodeNode interface
public:
    string ToXML(int i);
};

#endif // HTMLNODE_H
