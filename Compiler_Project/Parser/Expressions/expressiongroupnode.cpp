#include "expressiongroupnode.h"

ExpressionGroupNode::ExpressionGroupNode()
{

}

ExpressionGroupNode::ExpressionGroupNode(list<ExpressionNode *> *ls)
{
    this->Expressions=ls;
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
