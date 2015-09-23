#ifndef STATEMENTESCRIBANODE_H
#define STATEMENTESCRIBANODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"
using namespace std;

class StatementEscribaNode : public StatementNode
{
public:
    list<ExpressionNode*>*Expressions;
    StatementEscribaNode(list<ExpressionNode*>*expressions,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTESCRIBANODE_H
