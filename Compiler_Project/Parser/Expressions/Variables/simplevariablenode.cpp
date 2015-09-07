#include "simplevariablenode.h"

SimpleVariableNode::SimpleVariableNode(string id)
{
    this->ID=id;
}

string SimpleVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SimpleVariable>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i)+"</SimpleVariable>\n";

    return re ;
}
