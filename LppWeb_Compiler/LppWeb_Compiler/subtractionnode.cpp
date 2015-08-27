#include "subtractionnode.h"

SubtractionNode::SubtractionNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}

