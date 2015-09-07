#include "statementassignmentnode.h"

StatementAssignmentNode::StatementAssignmentNode(VariableNode *var, ExpressionNode *expr)
{
    this->Variable=var;
    this->Expression=expr;
}



string StatementAssignmentNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementAssignment>\n";
    re+=Expression->ToXML(i+1);

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementAssignment>\n";
    return re;
}
