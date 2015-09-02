#include "negativenumbernode.h"

NegativeNumberNode::NegativeNumberNode(ExpressionNode *expression)
{
    this->Expression=expression;
}



string NegativeNumberNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<NegativeNumber>\n";
    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</NegativeNumber>\n";
    return re;
}
