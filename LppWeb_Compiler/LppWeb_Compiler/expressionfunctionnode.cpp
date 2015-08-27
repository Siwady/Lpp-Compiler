#include "expressionfunctionnode.h"

ExpressionFunctionNode::ExpressionFunctionNode()
{

}

ExpressionFunctionNode::ExpressionFunctionNode(string id, list<ExpressionNode *> *expressions)
{
    this->ID=id;
    this->Expressions=expressions;
}

void ExpressionFunctionNode::Add(ExpressionNode* expression_node)
{
    this->Expressions->push_back(expression_node);
}

