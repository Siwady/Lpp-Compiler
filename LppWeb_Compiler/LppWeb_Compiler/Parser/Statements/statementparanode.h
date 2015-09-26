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
	~StatementParaNode() override;
	void Interpret() override;
	VariableNode* Variable;
    ExpressionNode* FirstExpression;
    ExpressionNode* SecondExpression;
    list<StatementNode*>* Statements;
    StatementParaNode(VariableNode* var,ExpressionNode* firstExp,ExpressionNode* secondExp,list<StatementNode*>* ls,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTPARANODE_H
