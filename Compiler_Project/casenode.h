#ifndef CASENODE_H
#define CASENODE_H
#include "literalnode.h"
#include "statementnode.h"

#include "helper.h"

class CaseNode
{
public:
    list<LiteralNode*>* Literals;
    list<StatementNode *> *Statements;
    CaseNode(list<LiteralNode*>* literals,list<StatementNode*>* statement);

    string ToXML(int i);
};

#endif // CASENODE_H
