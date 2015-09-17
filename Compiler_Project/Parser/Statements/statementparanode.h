#ifndef STATEMENTPARANODE_H
#define STATEMENTPARANODE_H
#include "statementnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include "helper.h"
#include "Semantic/semanticexception.h"

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
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTPARANODE_H
