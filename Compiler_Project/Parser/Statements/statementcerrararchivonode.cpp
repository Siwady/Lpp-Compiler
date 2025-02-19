#include "statementcerrararchivonode.h"

StatementCerrarArchivoNode::StatementCerrarArchivoNode(VariableNode *var, int row, int column)
{
    this->Variable=var;
    this->Row=row;
    this->Column=column;
}



string StatementCerrarArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementCerrarArcbivo>\n";

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementCerrarArchivo>\n";
    return re;
}


void StatementCerrarArchivoNode::ValidateSemantic()
{
    Variable->ValidateSemantic();
}
