#include "arrayvariablenode.h"

ArrayVariableNode::ArrayVariableNode()
{

}

ArrayVariableNode::ArrayVariableNode(list<ExpressionNode *> *ls, string id)
{
    this->ExpressionList=ls;
    this->ID=id;
}

