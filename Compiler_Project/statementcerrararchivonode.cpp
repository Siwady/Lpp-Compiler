#include "statementcerrararchivonode.h"

StatementCerrarArchivoNode::StatementCerrarArchivoNode(VariableNode *var)
{
    this->Variable=var;
}



string StatementCerrarArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementCerrarArcbivo>\n";

    re+=Variable->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</StatementCerrarArchivo>\n";
    return re;
}
