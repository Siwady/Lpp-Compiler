#include "statementsinode.h"

StatementSiNode::StatementSiNode(ExpressionNode *expr, list<StatementNode *> *statementSi, list<StatementNode *> *statementsSino)
{
    this->Expression=expr;
    this->StatementsSi=statementSi;
    this->StatementsSino=statementsSino;
}



string StatementSiNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementSi>\n";

    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<StatementsSi->size();j++){
        re+=Helper::GetElementStatementNode(StatementsSi,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<StatementsSino->size();j++){
        re+=Helper::GetElementStatementNode(StatementsSino,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementSi>\n";
    return re;
}
