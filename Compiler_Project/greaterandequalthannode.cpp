#include "greaterandequalthannode.h"

GreaterAndEqualThanNode::GreaterAndEqualThanNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string GreaterAndEqualThanNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<GreaterAndEqualOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</GreaterAndEqualOperation>\n";
    return re;
}
