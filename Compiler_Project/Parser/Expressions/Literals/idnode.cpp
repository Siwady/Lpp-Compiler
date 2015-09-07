#include "idnode.h"

IdNode::IdNode(string id)
{
    this->ID=id;
}



string IdNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ID>\n";
    re+=Helper::GetIdentation(i+1)+ID+"\n";
    re+=Helper::GetIdentation(i)+"</ID>\n";

    return re ;
}
