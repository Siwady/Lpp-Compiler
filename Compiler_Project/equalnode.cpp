#include "equalnode.h"

EqualNode::EqualNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string EqualNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<EqualOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</EquialOperation>\n";
    return re;
}
