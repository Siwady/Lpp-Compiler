#include "expressionfunctionnode.h"

ExpressionFunctionNode::ExpressionFunctionNode()
{

}

ExpressionFunctionNode::ExpressionFunctionNode(string id, list<ExpressionNode *> *expressions, int row, int column)
{
    this->ID=id;
    this->Expressions=expressions;
    this->Row=row;
    this->Column=column;
}

string ExpressionFunctionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ExpressionFunction>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";
    re+=Helper::GetIdentation(i)+"</ExpressionFunction>\n";
    return re;
}

Type *ExpressionFunctionNode::ValidateSemantic()
{
    Type* IdType=SymbolTable::GetInstance()->GetVariableType(ID);

    if(IdType->Name.compare("Function")!=0)
    {
        throw SemanticException("Se esperaba un Arreglo ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    if(dynamic_cast<FunctionType*>(IdType)->Params.size()!=this->Expressions->size())
    {
        throw SemanticException("Dimension incoherente del arreglo,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
/*
    list<ExpressionNode*>::const_iterator iterator;
    ExpressionNode *e;
    for (iterator = Expressions->begin(); iterator != Expressions->end(); ++iterator) {
        e=*iterator;
        if((e->NameType.compare("Entero")!=0))
        {
            throw SemanticException("Se esperaba tipo de dato entero,Fila:"+to_string(e->Row)+",Columna:"+to_string(e->Column));
        }
    }
*/
    return dynamic_cast<FunctionType*>(IdType)->ReturnType;
}
