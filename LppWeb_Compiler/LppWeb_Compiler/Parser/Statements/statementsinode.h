#ifndef STATEMENTSINODE_H
#define STATEMENTSINODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"
using namespace std;

class StatementSiNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* StatementsSi;
    list<StatementNode*>* StatementsSino;
    StatementSiNode(ExpressionNode* expr, list<StatementNode*>* statementSi, list<StatementNode*>* statementsSino,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTSINODE_H
