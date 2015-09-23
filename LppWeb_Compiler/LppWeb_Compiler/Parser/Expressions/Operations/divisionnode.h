#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "../expressionnode.h"

class DivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    DivisionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type* ValidateSemantic() override;
};

#endif // DIVISIONNODE_H
