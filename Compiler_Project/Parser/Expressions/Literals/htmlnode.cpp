#include "htmlnode.h"

HtmlNode::HtmlNode(string html)
{
    this->HTML=html;
}



string HtmlNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<HTML>\n";
    re+=Helper::GetIdentation(i+1)+HTML+"\n";
    re+=Helper::GetIdentation(i)+"</HTML>\n";

    return re ;
}
