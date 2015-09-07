#include "procedurenode.h"

ProcedureNode::ProcedureNode(string id, list<ParameterNode *> *param, list<DeclareVariableNode *> *vars, list<StatementNode *> *statements)
{
    this->ID=id;
    this->Params=param;
    this->Variables=vars;
    this->Statements=statements;
}

ProcedureNode::ProcedureNode()
{

}



string ProcedureNode::ToXML(int i)
{

    string re=Helper::GetIdentation(i)+"<Procedure>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";

    re+=Helper::GetIdentation(i+1)+"<ParamList>\n";
    for(int j=0;j<Params->size();j++){
        re+=Helper::GetElementParameterNode(Params,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ParamList>\n";
    re+=Helper::GetIdentation(i+1)+"<DeclareVariableList>\n";
    for(int j=0;j<Params->size();j++){
        re+=Helper::GetElementDeclareVariableNode(Variables,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</DeclareVariableList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</Procedure>\n";
    return re;
}
