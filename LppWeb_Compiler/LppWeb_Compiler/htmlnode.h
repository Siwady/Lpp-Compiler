#ifndef HTMLNODE_H
#define HTMLNODE_H
#include "programcodenode.h"
#include <string>
using namespace std;

class HtmlNode : public ProgramCodeNode
{
public:
    string HTML;
    HtmlNode(string html);
};

#endif // HTMLNODE_H
