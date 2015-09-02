#include "logicalynode.h"

LogicalYNode::LogicalYNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string LogicalYNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalYNodeOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LocalYNodeOperation>\n";
    return re;
}
