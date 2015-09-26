#ifndef STATEMENTRETURNNODE_H
#define STATEMENTRETURNNODE_H
#include "statementnode.h"
#include "../Expressions/expressionnode.h"

class StatementReturnNode : public StatementNode
{
public:
	~StatementReturnNode() override;
	void Interpret() override;
	ExpressionNode* Expression;
    StatementReturnNode(ExpressionNode* expr,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // STATEMENTRETURNNODE_H
