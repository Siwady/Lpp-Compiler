#include "declarevariablenode.h"

DeclareVariableNode::DeclareVariableNode(TypeNode *type, list<string> *ids, int row, int column)
{
    this->IDs=ids;
    this->Type=type;
    this->Row=row;
    this->Column=column;
}



string DeclareVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<DeclareVariableNode>\n";
    re+=Type->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<ID List>\n";
    for(int j=0;j<IDs->size();j++){
        re+=Helper::GetIdentation(i+2)+Helper::GetElementString(IDs,j);
    }
    re+=Helper::GetIdentation(i+1)+"</ID List>\n";
    re+=Helper::GetIdentation(i)+"</DeclareVariableNode>\n";

    return re ;
}
