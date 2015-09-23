#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "../expressionnode.h"

class GreaterThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterThanNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // GREATERTHANNODE_H
