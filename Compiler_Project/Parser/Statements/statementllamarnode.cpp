#include "statementllamarnode.h"

StatementLlamarNode::StatementLlamarNode(string id, list<ExpressionNode *> *ls)
{
    this->Expressions=ls;
    this->ID=id;
}



string StatementLlamarNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementLlamar>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";

    re+=Helper::GetIdentation(i)+"</StatementLlamar>\n";
    return re;
}
