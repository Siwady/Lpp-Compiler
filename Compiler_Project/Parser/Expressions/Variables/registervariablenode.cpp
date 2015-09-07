#include "registervariablenode.h"

RegisterVariableNode::RegisterVariableNode()
{

}

RegisterVariableNode::RegisterVariableNode(VariableNode *var1, VariableNode *var2)
{
    this->Variable1=var1;
    this->Variable2=var2;
}

string RegisterVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<RegisterVariable>\n";
    re+=Variable1->ToXML(i+1);
    re+=Variable2->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</RegisterVariable>\n";

    return re ;
}
