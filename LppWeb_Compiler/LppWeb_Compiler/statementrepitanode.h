#ifndef STATEMENTREPITANODE_H
#define STATEMENTREPITANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>

using namespace std;

class StatementRepitaNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* Statements;
    StatementRepitaNode(ExpressionNode* expr,list<StatementNode*>* ls);
};

#endif // STATEMENTREPITANODE_H
