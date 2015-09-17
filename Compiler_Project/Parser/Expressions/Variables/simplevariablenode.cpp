#include "simplevariablenode.h"

SimpleVariableNode::SimpleVariableNode(string id, int row, int column)
{
    this->ID=id;
    this->Column=column;
    this->Row=row;
    this->NameType="SimpleVariable";
}

string SimpleVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SimpleVariable>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i)+"</SimpleVariable>\n";

    return re ;
}

Type *SimpleVariableNode::ValidateSemantic()
{
    Type* IdType=SymbolTable::GetInstance()->GetVariableType(ID);

    if(IdType->Name.compare("SimpleVariable")!=0)
    {
        throw SemanticException("Se esperaba una variable simple ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    return dynamic_cast<SimpleVariableType*>(IdType)->OfType;
}
