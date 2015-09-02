#include "statementescribanode.h"

StatementEscribaNode::StatementEscribaNode(list<ExpressionNode *> *expressions)
{
    this->Expressions=expressions;
}



string StatementEscribaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementEscriba>\n";

    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";

    re+=Helper::GetIdentation(i)+"</StatementEscriba>\n";
    return re;
}
