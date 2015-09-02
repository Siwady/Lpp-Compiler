#ifndef LOGICALYNODE_H
#define LOGICALYNODE_H
#include "expressionnode.h"
#include "helper.h"

class LogicalYNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalYNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // LOGICALYNODE_H
