#ifndef HTMLNODE_H
#define HTMLNODE_H
#include "../../programcodenode.h"

class HtmlNode : public ProgramCodeNode
{
public:
    string HTML;
    HtmlNode(string html,int row,int column);

    // ProgramCodeNode interface
public:
    string ToXML(int i);

    // ProgramCodeNode interface
public:
    void ValidateSemantic() override;
};

#endif // HTMLNODE_H
