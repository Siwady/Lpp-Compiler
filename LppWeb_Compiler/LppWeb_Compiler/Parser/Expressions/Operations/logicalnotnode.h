#ifndef LOGICALNOTNODE_H
#define LOGICALNOTNODE_H
#include "../expressionnode.h"

class LogicalNotNode : public ExpressionNode
{
public:
	~LogicalNotNode() override;
	Value* Interpret() override;
	ExpressionNode *Expression;
    LogicalNotNode(ExpressionNode* expression, int row,int column);

    string ToXML(int i) override;

    Type *ValidateSemantic() override;
};

#endif // LOGICALNOTNODE_H
