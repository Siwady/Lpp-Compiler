#include "arrayvariablenode.h"

ArrayVariableNode::ArrayVariableNode()
{

}

ArrayVariableNode::ArrayVariableNode(list<ExpressionNode *> *ls, string id)
{
    this->ExpressionList=ls;
    this->ID=id;
}

string ArrayVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ArrayVariable>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<ExpressionList->size();j++){
        re+=Helper::GetElementExpressionNode(ExpressionList,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";
    re+=Helper::GetIdentation(i)+"</ArrayVariable>\n";

    return re ;
}
