#include "expressiongroupnode.h"

ExpressionGroupNode::ExpressionGroupNode()
{

}

ExpressionGroupNode::ExpressionGroupNode(list<ExpressionNode *> *ls)
{
    this->Expressions=ls;
}

