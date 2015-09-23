#include "proceduretype.h"

ProcedureType::ProcedureType(list<ParameterNode *> *params,list<DeclareVariableNode*> * local)
{
    this->Params=params;
	this->Name = "procedure";
	this->LocalVariables = local;
}

