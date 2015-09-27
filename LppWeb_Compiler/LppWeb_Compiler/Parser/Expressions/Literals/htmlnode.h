#ifndef HTMLNODE_H
#define HTMLNODE_H
#include "../../programcodenode.h"

class HtmlNode : public ProgramCodeNode
{
public:
	~HtmlNode() override;
	void Interpret() override;
	string HTML;
    HtmlNode(string html,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // HTMLNODE_H
