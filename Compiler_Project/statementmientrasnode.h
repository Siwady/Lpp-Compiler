#ifndef STATEMENTMIENTRASNODE_H
#define STATEMENTMIENTRASNODE_H
#include "statementnode.h"
#include "expressionnode.h"
#include <list>
#include "helper.h"

using namespace std;

class StatementMientrasNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>*Statements;
    StatementMientrasNode(ExpressionNode* expr,list<StatementNode*>* ls);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTMIENTRASNODE_H
