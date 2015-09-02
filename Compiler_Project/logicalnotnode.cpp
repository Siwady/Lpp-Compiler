#include "logicalnotnode.h"

LogicalNotNode::LogicalNotNode(ExpressionNode *expression)
{
    this->Expression=expression;
}



string LogicalNotNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalNotOperation>\n";
    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LogicalNotOperation>\n";
    return re;
}
