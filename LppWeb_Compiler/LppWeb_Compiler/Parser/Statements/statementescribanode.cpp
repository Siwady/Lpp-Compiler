#include "statementescribanode.h"
#include "../../helper.h"

StatementEscribaNode::StatementEscribaNode(list<ExpressionNode *> *expressions, int row, int column)
{
    this->Expressions=expressions;
    this->Row=row;
    this->Column=column;
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


void StatementEscribaNode::ValidateSemantic()
{
    list<ExpressionNode*>::const_iterator iterator;
    ExpressionNode* temp;
    for (iterator = Expressions->begin(); iterator != Expressions->end(); ++iterator) {
        temp=*iterator;
        temp->ValidateSemantic();
    }
}
