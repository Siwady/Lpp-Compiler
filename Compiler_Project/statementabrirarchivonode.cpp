#include "statementabrirarchivonode.h"

StatementAbrirArchivoNode::StatementAbrirArchivoNode(ExpressionNode *expr, VariableNode *var, list<string> *op)
{
    this->Expression=expr;
    this->Variable=var;
    this->Operators=op;
}

