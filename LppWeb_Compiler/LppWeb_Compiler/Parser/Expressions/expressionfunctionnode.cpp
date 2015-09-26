#include "expressionfunctionnode.h"
#include "../../Semantic/semanticexception.h"
#include "../../Semantic/symboltable.h"
#include "../../Semantic/Type/functiontype.h"
#include "../../helper.h"

ExpressionFunctionNode::~ExpressionFunctionNode()
{
	delete Expressions;
}

Value* ExpressionFunctionNode::Interpret()
{
	Type* t=SymbolTable::GetInstance()->GetVariableType(ID);
	FunctionType* f = dynamic_cast<FunctionType*>(t);
	SymbolTable::SetInFunction(ID);
	for (int j = 0; j < Expressions->size(); j++){
		f->LocalValues[Helper::GetElementParameterNode(f->Params, j)->ID] = Helper::GetElementExpressionNode(Expressions,j)->Interpret();
	}
	for (int i = 0; i < f->Statements->size(); i++)
	{
		Helper::GetElementStatementNode(f->Statements, i)->Interpret();
	}
	SymbolTable::SetInFunction("");
	return SymbolTable::GetInstance()->ReturnValue;
}

ExpressionFunctionNode::ExpressionFunctionNode()
{
	delete Expressions;
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

    if(Helper::ToLower(IdType->Name).compare("function")!=0)
    {
        throw SemanticException("Se esperaba un Arreglo ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

	FunctionType* type=dynamic_cast<FunctionType*>(IdType);
    if(type->Params->size()!=this->Expressions->size())
    {
        throw SemanticException("Dimension incoherente del arreglo,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

	ExpressionNode *e;
	string c;
	for (int i = 0; i < Expressions->size();i++){
		e = Helper::GetElementExpressionNode(Expressions, i);
		c = Helper::GetElementParameterNode(type->Params, i)->Type->OfType;
		if (Helper::ToLower(e->NameType).compare(Helper::ToLower(c)) != 0)
        {
            throw SemanticException("Se esperaba tipo de dato entero,Fila:"+to_string(e->Row)+",Columna:"+to_string(e->Column));
        }
    }
    return SymbolTable::GetInstance()->ReturnType;
}
