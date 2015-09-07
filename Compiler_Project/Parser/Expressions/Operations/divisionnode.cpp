#include "divisionnode.h"

DivisionNode::DivisionNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string DivisionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Divission>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</Division>\n";

    return re ;
}
