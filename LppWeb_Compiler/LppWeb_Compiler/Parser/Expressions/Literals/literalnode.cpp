#include "literalnode.h"
#include "../../../Semantic/Type/type.h"

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
