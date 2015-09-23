#include "functiontype.h"

FunctionType::FunctionType(Type* type, list<ParameterNode*> *ls, list<DeclareVariableNode*> *local)
{
	this->ReturnType = type;
	this->Params = ls;
	this->Name = "function";
	this->LocalVariables = local;
}