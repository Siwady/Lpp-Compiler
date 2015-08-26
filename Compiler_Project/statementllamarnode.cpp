#include "statementllamarnode.h"

StatementLlamarNode::StatementLlamarNode(string id, list<ExpressionNode *> *ls)
{
    this->Expressions=ls;
    this->ID=id;
}

