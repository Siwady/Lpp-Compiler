#include "parameternode.h"

ParameterNode::ParameterNode(TypeNode *type, string id, bool var)
{
    this->ID=id;
    this->Type=type;
    this->Var=var;
}

string ParameterNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Parameter>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Type->ToXML(i+1);
    re+=Helper::GetIdentation(i+1)+"<Var>\n";
    re+=Helper::GetIdentation(i+2)+to_string(Var)+"\n";
    re+=Helper::GetIdentation(i+1)+"</Var>\n";
    re+=Helper::GetIdentation(i)+"</Parameter>\n";
    return re;
}

