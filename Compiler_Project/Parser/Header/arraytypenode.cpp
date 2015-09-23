#include "arraytypenode.h"

ArrayTypeNode::ArrayTypeNode(TypeNode *type, list<int> *dim, int row, int column)
{
    this->Type=type;
    this->Dimentions=dim;
    this->Row=row;
    this->Column=column;
    this->OfType="arreglo";
}



string ArrayTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ArrayType>\n";
    re+=Type->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<Int List>\n";
    for(int j=0;j<Dimentions->size();j++){
        re+=Helper::GetIdentation(i+2)+to_string(Helper::GetElementInt(Dimentions,j));
    }
    re+=Helper::GetIdentation(i+1)+"</Int List>\n";
    re+=Helper::GetIdentation(i)+"</ArrayType>\n";

    return re ;
}


void ArrayTypeNode::ValidateSemantic()
{
}
