#include "variablenode.h"
#include "../../../Interpret/Values/value.h"

VariableNode::~VariableNode()
{
}

Value* VariableNode::Interpret()
{
	Value * v = new Value();
	return v;
}

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

