#include "cadenatypenode.h"

CadenaTypeNode::CadenaTypeNode(int size, int row, int column)
{
    this->Size=size;
    this->Row=row;
    this->Column=column;
    this->OfType="cadena";
}



string CadenaTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<CadenaType>\n";
    re+=Helper::GetIdentation(i+1)+"<Size>\n";
    re+=Helper::GetIdentation(i+2)+to_string(Size)+"\n";
    re+=Helper::GetIdentation(i+1)+"</Size>\n";
    re+=Helper::GetIdentation(i)+"</CadenaType>\n";

    return re ;
}
