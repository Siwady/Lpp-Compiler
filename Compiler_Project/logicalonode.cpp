#include "logicalonode.h"

LogicalONode::LogicalONode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string LogicalONode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalONodeOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LogicalONodeOperation>\n";
    return re;
}
