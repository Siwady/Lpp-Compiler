#ifndef STATEMENTREPITANODE_H
#define STATEMENTREPITANODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"

using namespace std;

class StatementRepitaNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* Statements;
    StatementRepitaNode(ExpressionNode* expr,list<StatementNode*>* ls,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTREPITANODE_H
