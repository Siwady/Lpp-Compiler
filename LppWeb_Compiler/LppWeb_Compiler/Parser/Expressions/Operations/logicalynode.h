#ifndef LOGICALYNODE_H
#define LOGICALYNODE_H
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class LogicalYNode : public ExpressionNode
{
public:
	~LogicalYNode() override;
	Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalYNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // LOGICALYNODE_H
