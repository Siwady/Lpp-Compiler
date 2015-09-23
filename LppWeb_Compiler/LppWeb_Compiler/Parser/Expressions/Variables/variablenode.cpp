#include "variablenode.h"

VariableNode::VariableNode()
{
}

string VariableNode::ToXML(int i)
{
    /*string re=Helper::GetIdentation(i)+"<Expression>\n";

    re+=Helper::GetIdentation(i)+"</Expression>\n";

    return re ;*/
    return "";
}

Type *VariableNode::ValidateSemantic()
{
    VariableNode* v=new VariableNode();
    return NULL;
}

