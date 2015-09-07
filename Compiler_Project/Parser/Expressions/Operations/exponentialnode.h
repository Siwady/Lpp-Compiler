#ifndef EXPONENTIALNODE_H
#define EXPONENTIALNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class ExponentialNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ExponentialNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // EXPONENTIALNODE_H
