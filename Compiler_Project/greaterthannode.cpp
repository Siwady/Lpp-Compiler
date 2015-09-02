#include "greaterthannode.h"

GreaterThanNode::GreaterThanNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string GreaterThanNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<GreaterThenOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</GreaterThanOperation>\n";
    return re;
}
