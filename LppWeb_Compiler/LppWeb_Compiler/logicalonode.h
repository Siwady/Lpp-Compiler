#ifndef LOGICALONODE_H
#define LOGICALONODE_H
#include "expressionnode.h"

class LogicalONode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalONode(ExpressionNode* left,ExpressionNode* right);
};

#endif // LOGICALONODE_H
