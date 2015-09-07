#include "statementparanode.h"

StatementParaNode::StatementParaNode(VariableNode *var, ExpressionNode *firstExp, ExpressionNode *secondExp, list<StatementNode *> *ls)
{
    this->Variable=var;
    this->FirstExpression=firstExp;
    this->SecondExpression=secondExp;
    this->Statements=ls;
}



string StatementParaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementPara>\n";

    re+=Variable->ToXML(i+1);
    re+=FirstExpression->ToXML(i+1);
    re+=SecondExpression->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</StatementPara>\n";
    return re;
}
