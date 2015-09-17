#ifndef EXPONENTIALNODE_H
#define EXPONENTIALNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/semanticexception.h";

class ExponentialNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ExponentialNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // EXPONENTIALNODE_H
