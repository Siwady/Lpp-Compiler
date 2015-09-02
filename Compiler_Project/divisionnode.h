#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "expressionnode.h"
#include "helper.h"

class DivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    DivisionNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // DIVISIONNODE_H
