#include "statementescribirarchivonode.h"
#include "../../helper.h"

StatementEscribirArchivoNode::StatementEscribirArchivoNode(list<ExpressionNode *> *ls, int row, int column)
{
    this->Expressions=ls;
    this->Row=row;
    this->Column=column;
}



string StatementEscribirArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementEscribirArchivo>\n";

    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";

    re+=Helper::GetIdentation(i)+"</StatementEscribirArchivo>\n";
    return re;
}


void StatementEscribirArchivoNode::ValidateSemantic()
{
    list<ExpressionNode*>::const_iterator iterator;
    ExpressionNode* temp;
    for (iterator = Expressions->begin(); iterator != Expressions->end(); ++iterator) {
        temp=*iterator;
        temp->ValidateSemantic();
    }
}
