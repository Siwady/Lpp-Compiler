#include "declareheadernode.h"

DeclareHeaderNode::DeclareHeaderNode(list<DeclareVariableNode *> *var)
{
    this->DeclareVariables=var;
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

