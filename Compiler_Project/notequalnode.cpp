#include "notequalnode.h"

NotEqualNode::NotEqualNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}

