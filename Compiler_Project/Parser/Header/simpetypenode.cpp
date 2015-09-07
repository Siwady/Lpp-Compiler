#include "simpetypenode.h"

SimpeTypeNode::SimpeTypeNode(string type)
{
    this->Type=type;
}



string SimpeTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SimpleType>\n";
    re+=Helper::GetIdentation(i+2)+Type+"\n";
    re+=Helper::GetIdentation(i)+"</SimpleType>\n";
    return re;
}
