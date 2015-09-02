#ifndef GREATERANDEQUALTHANNODE_H
#define GREATERANDEQUALTHANNODE_H
#include "expressionnode.h"
#include "helper.h"

class GreaterAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterAndEqualThanNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // GREATERANDEQUALTHANNODE_H
