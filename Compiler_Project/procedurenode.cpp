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

