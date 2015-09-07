#include "exponentialnode.h"

ExponentialNode::ExponentialNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string ExponentialNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ExponentialOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</ExponentialOperation>\n";
    return re;
}
