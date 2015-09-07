#ifndef STATEMENTPARANODE_H
#define STATEMENTPARANODE_H
#include "statementnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include "helper.h"

using namespace std;
class StatementParaNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* FirstExpression;
    ExpressionNode* SecondExpression;
    list<StatementNode*>* Statements;
    StatementParaNode(VariableNode* var,ExpressionNode* firstExp,ExpressionNode* secondExp,list<StatementNode*>* ls);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTPARANODE_H
