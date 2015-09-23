#include "expressionnode.h"
#include <string>
#include "../../Semantic/Type/type.h"
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

