#include "statementreturnnode.h"
#include "../../helper.h"
#include "../../Semantic/symboltable.h"

StatementReturnNode::~StatementReturnNode()
{
	delete Expression;
}

void StatementReturnNode::Interpret()
{
	SymbolTable::GetInstance()->ReturnValue = Expression->Interpret();
}

StatementReturnNode::StatementReturnNode(ExpressionNode *expr, int row, int column)
{
    this->Expression=expr;
    this->Row=row;
    this->Column=column;
}



string StatementReturnNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementReturn>\n";

    re+=Expression->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementReturn>\n";
    return re;
}


void StatementReturnNode::ValidateSemantic()
{
    Type* type=Expression->ValidateSemantic();
	if (SymbolTable::GetInstance()->ReturnType != nullptr){
		if (SymbolTable::GetInstance()->ReturnType->Name != type->Name)
		{
			throw SemanticException("Valor de retorno deberia ser de tipo " + SymbolTable::GetInstance()->ReturnType->Name + ",Fila:" + to_string(Row) + ",Columna:" + to_string(Column));
		}
	}
}
