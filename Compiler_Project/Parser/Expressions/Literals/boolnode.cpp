#include "boolnode.h"

BoolNode::BoolNode(string boolean)
{
    this->Booolean=boolean;
}



string BoolNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Booleano>\n";
    re+=Helper::GetIdentation(i)+Booolean+"\n";
    re+=Helper::GetIdentation(i)+"</Booleano>\n";

    return re ;
}
