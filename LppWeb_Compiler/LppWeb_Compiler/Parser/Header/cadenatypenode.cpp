#include "cadenatypenode.h"
#include "../../Semantic/symboltable.h"
#include "../../helper.h"

CadenaTypeNode::~CadenaTypeNode()
{
}

void CadenaTypeNode::Interpret()
{

}

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


void CadenaTypeNode::ValidateSemantic()
{
    SymbolTable::GetInstance()->ExistType(OfType);
}
