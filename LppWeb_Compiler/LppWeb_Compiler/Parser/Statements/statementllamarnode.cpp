#include "statementllamarnode.h"
#include "../../Semantic/semanticexception.h"
#include "../../Semantic/symboltable.h"
#include "../../Semantic/Type/proceduretype.h"
#include "../../helper.h"

StatementLlamarNode::~StatementLlamarNode()
{
	delete Expressions;
}

void StatementLlamarNode::Interpret()
{
	Type* t = SymbolTable::GetInstance()->GetVariableType(ID);
	
	ProcedureType* f = dynamic_cast<ProcedureType*>(t);

	for (int j = 0; j < Expressions->size(); j++){
		f->LocalValues[Helper::GetElementParameterNode(f->Params, j)->ID] = Helper::GetElementExpressionNode(Expressions, j)->Interpret();
	}
	for (int i = 0; i<Expressions->size(); i++)
	{
		Value* a=Helper::GetElementExpressionNode(Expressions, i)->Interpret();

	}


	SymbolTable::SetInFunction(ID);
	for (int i = 0; i < f->Statements->size(); i++)
	{
		Helper::GetElementStatementNode(f->Statements, i)->Interpret();
	}
	SymbolTable::SetInFunction("");
}

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
    if(Helper::ToLower(var->Name)!="procedure")
    {
        throw SemanticException("Se esperaba un Procedimiento,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
    ProcedureType* t=dynamic_cast<ProcedureType*>(var);
    if(t->Params->size()!= Expressions->size())
    {
        throw SemanticException("Error de dimensiones ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    for(int i=0;i<Expressions->size();i++)
    {
		string a = Helper::ToLower(Helper::GetElementExpressionNode(Expressions, i)->NameType);
		string b = Helper::ToLower(Helper::GetElementParameterNode(t->Params, i)->Type->OfType);
        if(a!=b)
        {
			throw SemanticException("Se esperaba" + Helper::GetElementParameterNode(t->Params, i)->Type->OfType + " ,Fila:" + to_string(Helper::GetElementParameterNode(t->Params, i)->Row) + ",Columna:" + to_string(Helper::GetElementParameterNode(t->Params, i)->Column));
        }
    }
}
