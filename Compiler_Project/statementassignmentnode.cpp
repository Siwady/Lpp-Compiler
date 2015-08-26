#include "statementassignmentnode.h"

StatementAssignmentNode::StatementAssignmentNode(VariableNode *var, ExpressionNode *expr)
{
    this->Variable=var;
    this->Expression=expr;
}

