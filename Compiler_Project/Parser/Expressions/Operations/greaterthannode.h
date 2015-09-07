#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class GreaterThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterThanNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // GREATERTHANNODE_H
