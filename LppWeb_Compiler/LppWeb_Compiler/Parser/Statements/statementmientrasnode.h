#ifndef STATEMENTMIENTRASNODE_H
#define STATEMENTMIENTRASNODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"

using namespace std;

class StatementMientrasNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>*Statements;
    StatementMientrasNode(ExpressionNode* expr,list<StatementNode*>* ls,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTMIENTRASNODE_H
