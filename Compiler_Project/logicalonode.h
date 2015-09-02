#ifndef LOGICALONODE_H
#define LOGICALONODE_H
#include "expressionnode.h"
#include"helper.h"

class LogicalONode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalONode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // LOGICALONODE_H
