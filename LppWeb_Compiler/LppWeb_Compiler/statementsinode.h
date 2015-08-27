#ifndef STATEMENTSINODE_H
#define STATEMENTSINODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>
using namespace std;

class StatementSiNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* StatementsSi;
    list<StatementNode*>* StatementsSino;
    StatementSiNode(ExpressionNode* expr, list<StatementNode*>* statementSi, list<StatementNode*>* statementsSino);
};

#endif // STATEMENTSINODE_H
