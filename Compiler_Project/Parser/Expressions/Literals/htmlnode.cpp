#include "htmlnode.h"

HtmlNode::HtmlNode(string html, int row, int column)
{
    this->HTML=html;
    this->Row=row;
    this->Column=column;
}



string HtmlNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<HTML>\n";
    re+=Helper::GetIdentation(i+1)+HTML+"\n";
    re+=Helper::GetIdentation(i)+"</HTML>\n";

    return re ;
}


void HtmlNode::ValidateSemantic()
{

}
