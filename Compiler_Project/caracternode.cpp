#include "caracternode.h"

CaracterNode::CaracterNode(char caracter)
{
    this->Caracter=caracter;
}



string CaracterNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Caracter>\n";
    re+=Helper::GetIdentation(i)+Caracter+"\n";
    re+=Helper::GetIdentation(i)+"</Caracter>\n";

    return re ;
}
