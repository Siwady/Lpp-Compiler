#include "simplevariablenode.h"
#include "../../../Semantic/symboltable.h"
#include "../../../helper.h"
#include "../../../Semantic/Type/simplevariabletype.h"

SimpleVariableNode::SimpleVariableNode(string id, int row, int column)
{
    this->ID=id;
    this->Column=column;
    this->Row=row;
	//this->NameType = SymbolTable::GetInstance()->GetVariableType(ID)->Name;;
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
	Type* IdType = SymbolTable::GetInstance()->GetVariableType(ID);

	SymbolTable::GetInstance()->ExistType(Helper::ToLower(IdType->Name));
	//if ()
   /* {
        throw SemanticException("Se esperaba una variable simple ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }*/

	return SymbolTable::GetInstance()->GetVariableType(ID);//dynamic_cast<SimpleVariableType*>(IdType)->OfType;
}
