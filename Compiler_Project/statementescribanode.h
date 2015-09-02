#ifndef STATEMENTESCRIBANODE_H
#define STATEMENTESCRIBANODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>
#include "helper.h"
using namespace std;

class StatementEscribaNode : public StatementNode
{
public:
    list<ExpressionNode*>*Expressions;
    StatementEscribaNode(list<ExpressionNode*>*expressions);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTESCRIBANODE_H
