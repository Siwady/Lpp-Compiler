#include "expressiongroupnode.h"
#include "../../helper.h"

Value* ExpressionGroupNode::Interpret()
{
	return Helper::GetElementExpressionNode(Expressions, 0)->Interpret();
}

ExpressionGroupNode::~ExpressionGroupNode()
{
}

Type* ExpressionGroupNode::ValidateSemantic()
{
	return Helper::GetElementExpressionNode(Expressions, 0)->ValidateSemantic();
}

ExpressionGroupNode::ExpressionGroupNode()
{

}

ExpressionGroupNode::ExpressionGroupNode(list<ExpressionNode *> *ls, int row, int column)
{
    this->Expressions=ls;
    this->Row=row;
    this->Column=column;
	
}



string ExpressionGroupNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ExpressionGroup>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";
    re+=Helper::GetIdentation(i)+"</ExpressionGroup>\n";
    return re;
}
