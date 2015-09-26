#include "arrayvariablenode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/arreglotype.h"
#include "../../../helper.h"
#include "../../../Semantic/symboltable.h"

ArrayVariableNode::~ArrayVariableNode()
{
	delete ExpressionList;
}

Value* ArrayVariableNode::Interpret()
{
	return SymbolTable::GetInstance()->GetVariableValue(ID);
}

ArrayVariableNode::ArrayVariableNode()
{

}

ArrayVariableNode::ArrayVariableNode(list<ExpressionNode *> *ls, string id, int row, int column)
{
    this->ExpressionList=ls;
    this->ID=id;
    this->Row=row;
    this->Column=column;
    this->NameType="Arreglo";
}

string ArrayVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ArrayVariable>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<ExpressionList->size();j++){
        re+=Helper::GetElementExpressionNode(ExpressionList,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";
    re+=Helper::GetIdentation(i)+"</ArrayVariable>\n";

    return re ;
}


Type *ArrayVariableNode::ValidateSemantic()
{
    Type* IdType=SymbolTable::GetInstance()->GetVariableType(ID);

    if(IdType->Name.compare("Arreglo")!=0)
    {
        throw SemanticException("Se esperaba un Arreglo ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    if(dynamic_cast<ArregloType*>(IdType)->Dimention->size()!=this->ExpressionList->size())
    {
        throw SemanticException("Dimension incoherente del arreglo,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    list<ExpressionNode*>::const_iterator iterator;
    ExpressionNode *e;
    for (iterator = ExpressionList->begin(); iterator != ExpressionList->end(); ++iterator) {
        e=*iterator;
        if((e->NameType.compare("Entero")!=0))
        {
            throw SemanticException("Se esperaba tipo de dato entero,Fila:"+to_string(e->Row)+",Columna:"+to_string(e->Column));
        }
    }

    return dynamic_cast<ArregloType*>(IdType)->ArrayType;
}
