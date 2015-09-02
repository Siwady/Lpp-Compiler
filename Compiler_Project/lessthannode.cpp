#include "lessthannode.h"

LessThanNode::LessThanNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string LessThanNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LessThenOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LessThanOperation>\n";
    return re;
}
