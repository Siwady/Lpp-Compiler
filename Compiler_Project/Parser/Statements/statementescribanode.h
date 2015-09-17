#ifndef STATEMENTESCRIBANODE_H
#define STATEMENTESCRIBANODE_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include "helper.h"
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
