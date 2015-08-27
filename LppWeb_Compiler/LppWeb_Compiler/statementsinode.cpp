#include "statementsinode.h"

StatementSiNode::StatementSiNode(ExpressionNode *expr, list<StatementNode *> *statementSi, list<StatementNode *> *statementsSino)
{
    this->Expression=expr;
    this->StatementsSi=statementSi;
    this->StatementsSino=statementsSino;
}

