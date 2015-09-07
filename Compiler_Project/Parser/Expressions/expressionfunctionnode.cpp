#include "expressionfunctionnode.h"

ExpressionFunctionNode::ExpressionFunctionNode()
{

}

ExpressionFunctionNode::ExpressionFunctionNode(string id, list<ExpressionNode *> *expressions)
{
    this->ID=id;
    this->Expressions=expressions;
}

string ExpressionFunctionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ExpressionFunction>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";
    re+=Helper::GetIdentation(i)+"</ExpressionFunction>\n";
    return re;
}
