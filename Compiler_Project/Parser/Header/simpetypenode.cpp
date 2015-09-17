#include "simpetypenode.h"

SimpeTypeNode::SimpeTypeNode(string type, int row, int column)
{
    this->OfType=type;
    this->Row=row;
    this->Column=column;
}



string SimpeTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SimpleType>\n";
    re+=Helper::GetIdentation(i+2)+OfType+"\n";
    re+=Helper::GetIdentation(i)+"</SimpleType>\n";
    return re;
}
