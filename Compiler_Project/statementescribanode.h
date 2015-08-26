#ifndef STATEMENTESCRIBANODE_H
#define STATEMENTESCRIBANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>
using namespace std;

class StatementEscribaNode : public StatementNode
{
public:
    list<ExpressionNode*>*Expressions;
    StatementEscribaNode(list<ExpressionNode*>*expressions);
};

#endif // STATEMENTESCRIBANODE_H
