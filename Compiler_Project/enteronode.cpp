#include "enteronode.h"

EnteroNode::EnteroNode(int entero)
{
    this->Entero=entero;
}



string EnteroNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Entero>\n";
    re+=Helper::GetIdentation(i+1)+to_string(Entero)+"\n";
    re+=Helper::GetIdentation(i)+"</Entero>\n";

    return re ;
}
