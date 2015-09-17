#include "declareheadernode.h"

DeclareHeaderNode::DeclareHeaderNode(list<DeclareVariableNode *> *var, int row, int column)
{
    this->DeclareVariables=var;
    this->Row=row;
    this->Column=column;
}

string DeclareHeaderNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<DeclareHeaderNode>\n";

    re+=Helper::GetIdentation(i+1)+"<DeclareVariableNodeList>\n";
    for(int j=0;j<DeclareVariables->size();j++){
        re+=Helper::GetElementDeclareVariableNode(DeclareVariables,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</DeclareVariableNodeList>\n";

    re+=Helper::GetIdentation(i)+"</DeclareHeaderNode>\n";
    return re ;
}

