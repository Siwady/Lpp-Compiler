#include "registerstructurenode.h"

RegisterStructureNode::RegisterStructureNode(string Id, list<DeclareVariableNode *> *attr, int row, int column)
{
    this->ID=Id;
    this->Attributes=attr;
    this->Row=row;
    this->Column=column;
}



string RegisterStructureNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<RegisterStructure>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";

    re+=Helper::GetIdentation(i+1)+"<DeclareVariable>\n";
    for(int j=0;j<Attributes->size();j++){
        re+=Helper::GetElementDeclareVariableNode(Attributes,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</DeclareVariable>\n";
    re+=Helper::GetIdentation(i)+"</RegisterStructure>\n";
    return re;
}
