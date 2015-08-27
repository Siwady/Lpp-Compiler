#include "statementmientrasnode.h"

StatementMientrasNode::StatementMientrasNode(ExpressionNode *expr, list<StatementNode *> *ls)
{
    this->Expression=expr;
    this->Statements=ls;
}

