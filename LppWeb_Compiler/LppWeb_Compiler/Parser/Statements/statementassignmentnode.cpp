#include "statementassignmentnode.h"
#include "../../Semantic/semanticexception.h"
#include "../../helper.h"
#include "../../Semantic/symboltable.h"

StatementAssignmentNode::~StatementAssignmentNode()
{
	delete Variable;
	delete Expression;
}

void StatementAssignmentNode::Interpret()
{
	SymbolTable::GetInstance()->SetVariableValue(Variable->ID, Expression->Interpret());
}

StatementAssignmentNode::StatementAssignmentNode(VariableNode *var, ExpressionNode *expr, int row, int column)
{
    this->Variable=var;
    this->Expression=expr;
    this->Row=row;
    this->Column=column;
}



string StatementAssignmentNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementAssignment>\n";
    re+=Expression->ToXML(i+1);

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementAssignment>\n";
    return re;
}

void StatementAssignmentNode::ValidateSemantic()
{
    Type* var=Variable->ValidateSemantic();
    Type* exp=Expression->ValidateSemantic();
	if (var->Name.compare(exp->Name) != 0 || (Helper::ToLower(var->Name) == "entero" && Helper::ToLower(exp->Name) == "real") || Helper::ToLower(var->Name) == "real" && Helper::ToLower(exp->Name) == "entero")
    {
        throw SemanticException("Tipo de datos incompatibles:"+var->Name +exp->Name+ ", Fila:"+to_string(Expression->Row)+",Columna:"+to_string(Expression->Column));
    }
}
