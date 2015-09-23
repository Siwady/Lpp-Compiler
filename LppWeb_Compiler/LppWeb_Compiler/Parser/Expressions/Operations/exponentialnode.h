#ifndef EXPONENTIALNODE_H
#define EXPONENTIALNODE_H
#include <string>
#include "../expressionnode.h"

//#include "Semantic/semanticexception.h";

class ExponentialNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ExponentialNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
	std::string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // EXPONENTIALNODE_H
