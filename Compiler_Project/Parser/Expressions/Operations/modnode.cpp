#include "modnode.h"

ModNode::ModNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string ModNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ModNodeOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</ModNodeOperation>\n";
    return re;
}
