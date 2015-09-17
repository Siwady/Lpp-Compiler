#include "archivotypenode.h"

ArchivoTypeNode::ArchivoTypeNode(string Name, TypeNode *type, int row, int column)
{
    this->Name=Name;
    this->Types=type;
    this->Row=row;
    this->Column=column;
    this->OfType="archivo";
}



string ArchivoTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ArchivoType>\n";
    re+=Helper::GetIdentation(i+1)+"<Type>\n";
    re+=Helper::GetIdentation(i+2)+Name+"\n";
    re+=Helper::GetIdentation(i+1)+"</Type>\n";
    re+=Types->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</ArchivoType>\n";

    return re ;
}


void ArchivoTypeNode::ValidateSemantic()
{
    SymbolTable::GetInstance()->DeclareVariable(Name,Helper::GetTypeFromTypeNode(this->Types));
}
