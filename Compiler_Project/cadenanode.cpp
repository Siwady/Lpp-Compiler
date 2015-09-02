#include "cadenanode.h"

CadenaNode::CadenaNode(string cadena)
{
    this->Cadena=cadena;
}



string CadenaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Cadena>\n";
    re+=Helper::GetIdentation(i)+Cadena+"\n";
    re+=Helper::GetIdentation(i)+"</Cadena>\n";

    return re ;
}
