#ifndef STATEMENTPARANODE_H
#define STATEMENTPARANODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/Variables/variablenode.h"
#include "../Expressions/expressionnode.h"

using namespace std;
class StatementParaNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* FirstExpression;
    ExpressionNode* SecondExpression;
    list<StatementNode*>* Statements;
    StatementParaNode(VariableNode* var,ExpressionNode* firstExp,ExpressionNode* secondExp,list<StatementNode*>* ls,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i) override;

    // StatementNode interface
public:
    void ValidateSemantic() override;
};

#endif // STATEMENTPARANODE_H
