#ifndef STATEMENTREPITANODE_H
#define STATEMENTREPITANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>
#include "helper.h"

using namespace std;

class StatementRepitaNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* Statements;
    StatementRepitaNode(ExpressionNode* expr,list<StatementNode*>* ls);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTREPITANODE_H
