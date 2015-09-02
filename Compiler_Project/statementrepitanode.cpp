#include "statementrepitanode.h"

StatementRepitaNode::StatementRepitaNode(ExpressionNode *expr, list<StatementNode *> *ls)
{
    this->Expression=expr;
    this->Statements=ls;
}



string StatementRepitaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementRepita>\n";

    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementRepita>\n";
    return re;
}
