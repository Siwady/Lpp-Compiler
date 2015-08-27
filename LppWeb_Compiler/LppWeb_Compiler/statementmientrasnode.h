#ifndef STATEMENTMIENTRASNODE_H
#define STATEMENTMIENTRASNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>

using namespace std;

class StatementMientrasNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>*Statements;
    StatementMientrasNode(ExpressionNode* expr,list<StatementNode*>* ls);
};

#endif // STATEMENTMIENTRASNODE_H
