#include "expressionnode.h"
#include <string>
#include "../../Semantic/Type/type.h"
#include "../../Interpret/Values/value.h"
using namespace std;

ExpressionNode::ExpressionNode()
{

}

string ExpressionNode::ToXML(int i)
{
    /*string re=Helper::GetIdentation(i)+"<Expression>\n";

    re+=Helper::GetIdentation(i)+"</Expression>\n";

    return re ;*/
    return "";
}

Type *ExpressionNode::ValidateSemantic()
{
    Type* e=new Type();
    return e;
}

Value* ExpressionNode::Interpret()
{
	Value* v = new Value();
	return v;
}
