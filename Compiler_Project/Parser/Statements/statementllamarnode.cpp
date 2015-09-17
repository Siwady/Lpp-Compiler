#include "statementllamarnode.h"

StatementLlamarNode::StatementLlamarNode(string id, list<ExpressionNode *> *ls, int row, int column)
{
    this->Expressions=ls;
    this->ID=id;
    this->Row=row;
    this->Column=column;
}



string StatementLlamarNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementLlamar>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";

    re+=Helper::GetIdentation(i)+"</StatementLlamar>\n";
    return re;
}


void StatementLlamarNode::ValidateSemantic()
{
    Type* var=SymbolTable::GetInstance()->GetVariableType(ID);
    if(var->Name!="Procedure")
    {
        throw SemanticException("Se esperaba un Procedimiento,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
    ProcedureType* t=dynamic_cast<ProcedureType*>(var);
    if(t->Expressions.size()!= Expressions->size())
    {
        throw SemanticException("Error de dimensiones ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    for(int i=0;i<Expressions->size();i++)
    {
        if(Helper::GetElementExpressionNode(Expressions,i)->NameType.compare(Helper::GetElementExpressionNode(&t->Expressions,i)->NameType)!=0)
        {
            throw SemanticException("Se esperaba"+Helper::GetElementExpressionNode(&t->Expressions,i)->NameType +" ,Fila:"+to_string(Helper::GetElementExpressionNode(&t->Expressions,i)->Row)+",Columna:"+to_string(Helper::GetElementExpressionNode(&t->Expressions,i)->Column));
        }
    }
}
