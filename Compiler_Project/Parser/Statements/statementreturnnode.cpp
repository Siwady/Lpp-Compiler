#include "statementreturnnode.h"

StatementReturnNode::StatementReturnNode(ExpressionNode *expr, int row, int column)
{
    this->Expression=expr;
    this->Row=row;
    this->Column=column;
}



string StatementReturnNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementReturn>\n";

    re+=Expression->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementReturn>\n";
    return re;
}


void StatementReturnNode::ValidateSemantic()
{
    Expression->ValidateSemantic();
}
