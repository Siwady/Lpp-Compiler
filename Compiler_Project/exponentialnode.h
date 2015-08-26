#ifndef EXPONENTIALNODE_H
#define EXPONENTIALNODE_H
#include "expressionnode.h"

class ExponentialNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ExponentialNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // EXPONENTIALNODE_H
