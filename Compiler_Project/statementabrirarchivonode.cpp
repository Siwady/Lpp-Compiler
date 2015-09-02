#include "statementabrirarchivonode.h"

StatementAbrirArchivoNode::StatementAbrirArchivoNode(ExpressionNode *expr, VariableNode *var, list<string> *op)
{
    this->Expression=expr;
    this->Variable=var;
    this->Operators=op;
}



string StatementAbrirArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementAbrirArchivo>\n";
    re+=Expression->ToXML(i+1);

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<Operators>\n";
    for(int j=0;j<Operators->size();j++){
        re+=Helper::GetIdentation(i+2)+Helper::GetElementString(Operators,j);
    }
    re+=Helper::GetIdentation(i+1)+"</Operators>\n";

    re+=Helper::GetIdentation(i)+"</StatementAbrirArchivo>\n";
    return re;
}
