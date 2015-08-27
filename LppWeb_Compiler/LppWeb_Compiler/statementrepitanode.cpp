#include "statementrepitanode.h"

StatementRepitaNode::StatementRepitaNode(ExpressionNode *expr, list<StatementNode *> *ls)
{
    this->Expression=expr;
    this->Statements=ls;
}

