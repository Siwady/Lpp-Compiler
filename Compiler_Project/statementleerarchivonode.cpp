#include "statementleerarchivonode.h"

StatementLeerArchivoNode::StatementLeerArchivoNode(list<VariableNode *> *var)
{
    this->Variables=var;
}



string StatementLeerArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementLeerArchivo>\n";

    re+=Helper::GetIdentation(i+1)+"<VariableList>\n";
    for(int j=0;j<Variables->size();j++){
        re+=Helper::GetElementVariableNode(Variables,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</VariableList>\n";

    re+=Helper::GetIdentation(i)+"</StatementLeerArchivo>\n";
    return re;
}
