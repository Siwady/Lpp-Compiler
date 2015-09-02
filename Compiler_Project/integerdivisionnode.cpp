#include "integerdivisionnode.h"

IntegerDivisionNode::IntegerDivisionNode(ExpressionNode* left,ExpressionNode* right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string IntegerDivisionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<DivisionOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</DivisionOperation>\n";
    return re;
}
