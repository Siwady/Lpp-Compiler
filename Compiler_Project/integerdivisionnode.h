#ifndef INTEGERDIVISIONNODE_H
#define INTEGERDIVISIONNODE_H
#include "expressionnode.h"
#include "helper.h"

class IntegerDivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    IntegerDivisionNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // INTEGERDIVISIONNODE_H
