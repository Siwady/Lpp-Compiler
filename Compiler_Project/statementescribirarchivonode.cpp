#include "statementescribirarchivonode.h"

StatementEscribirArchivoNode::StatementEscribirArchivoNode(list<ExpressionNode *> *ls)
{
    this->Expressions=ls;
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
