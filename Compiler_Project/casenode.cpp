#include "casenode.h"

CaseNode::CaseNode(list<LiteralNode *> *literals, list<StatementNode *> *statement)
{
    this->Literals=literals;
    this->Statements=statement;
}

