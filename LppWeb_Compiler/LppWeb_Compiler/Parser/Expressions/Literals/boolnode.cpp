#include "boolnode.h"
#include "../../../helper.h"

BoolNode::BoolNode(string boolean, int row, int column)
{
    this->Booolean=boolean;
    this->Row=row;
    this->Column=column;
    this->NameType="Booleano";
}



string BoolNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Booleano>\n";
    re+=Helper::GetIdentation(i)+Booolean+"\n";
    re+=Helper::GetIdentation(i)+"</Booleano>\n";

    return re ;
}

Type *BoolNode::ValidateSemantic()
{
    BooleanType * b=new BooleanType();
    return b;
}

