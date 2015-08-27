#ifndef CASENODE_H
#define CASENODE_H
#include "literalnode.h"
#include "statementnode.h"
#include <list>
using namespace std;

class CaseNode
{
public:
    list<LiteralNode*>* Literals;
    list<StatementNode*>* Statements;
    CaseNode(list<LiteralNode*>* literals,list<StatementNode*>* statement);
};

#endif // CASENODE_H
