#ifndef EXPONENTIALNODE_H
#define EXPONENTIALNODE_H
#include <string>
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class ExponentialNode : public ExpressionNode
{
public:
	~ExponentialNode() override;
	Value* Interpret() override;
	ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ExponentialNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

	string ToXML(int i) override;

    Type* ValidateSemantic() override;
};

#endif // EXPONENTIALNODE_H
