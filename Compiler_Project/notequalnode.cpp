#include "notequalnode.h"

NotEqualNode::NotEqualNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string NotEqualNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<NotEqualOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</NotEqualOperation>\n";
    return re;
}
