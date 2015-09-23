#include "caracternode.h"
#include "../../../helper.h"

CaracterNode::CaracterNode(char caracter, int row, int column)
{
    this->Caracter=caracter;
    this->Row=row;
    this->Column=column;
    this->NameType="Caracter";
}



string CaracterNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Caracter>\n";
    re+=Helper::GetIdentation(i)+Caracter+"\n";
    re+=Helper::GetIdentation(i)+"</Caracter>\n";

    return re ;
}


Type *CaracterNode::ValidateSemantic()
{
    CaracterType* c=new CaracterType();
    return c;
}
