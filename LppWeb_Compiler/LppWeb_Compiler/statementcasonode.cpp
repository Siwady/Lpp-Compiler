#include "statementcasonode.h"

StatementCasoNode::StatementCasoNode(VariableNode *var, list<CaseNode *> *cases, list<StatementNode *> *sinocase)
{
    this->Variable=var;
    this->Cases=cases;
    this->SinoCase=sinocase;
}

