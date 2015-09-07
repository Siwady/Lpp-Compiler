#include "statementreturnnode.h"

StatementReturnNode::StatementReturnNode(ExpressionNode *expr)
{
    this->Expression=expr;
}



string StatementReturnNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementReturn>\n";

    re+=Expression->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementReturn>\n";
    return re;
}
