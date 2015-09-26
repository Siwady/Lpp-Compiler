#include "literalnode.h"
#include "../../../Semantic/Type/type.h"
#include "../../../Interpret/Values/value.h"

LiteralNode::~LiteralNode()
{
}

Value* LiteralNode::Interpret()
{
	Value* v = new Value();
	return v;
}

LiteralNode::LiteralNode()
{
}

string LiteralNode::ToXML(int i)
{
    return "";
}

Type *LiteralNode::ValidateSemantic()
{
    Type* l=new Type();
    return l;
}
