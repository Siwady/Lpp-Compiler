#include "casenode.h"

CaseNode::CaseNode(list<LiteralNode *> *literals, list<StatementNode *> *statement)
{
    this->Literals=literals;
    this->Statements=statement;
}

string CaseNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<CaseNode>\n";
    re+=Helper::GetIdentation(i+1)+"<LiteralNodeList>\n";
    for(int j=0;j<Literals->size();j++){
        re+=Helper::GetElementLiteralNode(Literals,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</LiteralNodeList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementNodeList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementNodeList>\n";
    re+=Helper::GetIdentation(i)+"</CaseNode>\n";

    return re ;
}

