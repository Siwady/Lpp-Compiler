#include "sumnode.h"

SumNode::SumNode(ExpressionNode* left,ExpressionNode* right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string SumNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SumOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</SumOperation>\n";
    return re;
}
