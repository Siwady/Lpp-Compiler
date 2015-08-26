#ifndef STATEMENTPARANODE_H
#define STATEMENTPARANODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "expressionnode.h"
#include <list>

using namespace std;
class StatementParaNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* FirstExpression;
    ExpressionNode* SecondExpression;
    list<StatementNode*>* Statements;
    StatementParaNode(VariableNode* var,ExpressionNode* firstExp,ExpressionNode* secondExp,list<StatementNode*>* ls);
};

#endif // STATEMENTPARANODE_H
