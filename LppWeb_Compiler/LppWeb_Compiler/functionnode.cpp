#include "functionnode.h"

FunctionNode::FunctionNode(string id, list<ParameterNode *> *param, TypeNode *type, list<DeclareVariableNode *> *vars, list<StatementNode *> *statements)
{
    this->ID=id;
    this->Params=param;
    this->ReturnType=type;
    this->Variables=vars;
    this->Statements=statements;
}

