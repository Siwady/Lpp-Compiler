#include "multiplicationnode.h"

MultiplicationNode::MultiplicationNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string MultiplicationNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<MultiplicationOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</MultiplicationOperation>\n";
    return re;
}
