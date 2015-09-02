#include "subtractionnode.h"

SubtractionNode::SubtractionNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string SubtractionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SubtractionOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</SubtractionOperation>\n";
    return re;
}
