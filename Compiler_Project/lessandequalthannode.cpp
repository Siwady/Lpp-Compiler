#include "lessandequalthannode.h"

LessAndEqualThanNode::LessAndEqualThanNode(ExpressionNode *left, ExpressionNode *right)
{
    this->LeftNode=left;
    this->RightNode=right;
}



string LessAndEqualThanNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LessAndEqualThanOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LessAndEqualThanOperation>\n";
    return re;
}
