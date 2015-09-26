#include "functiontype.h"
#include "../../helper.h"
#include "../symboltable.h"

FunctionType::~FunctionType()
{
	delete ReturnType;
	delete Params;
	delete LocalVariables;
}

string FunctionType::GetName()
{
	return Name;
}

Value* FunctionType::DefaultValue()
{
	for (int i = 0; i < Params->size(); i++)
	{
		LocalValues[Helper::ToLower(Helper::GetElementParameterNode(Params, i)->ID)] = Helper::GetTypeFromTypeNode(Helper::GetElementParameterNode(Params, i)->Type)->DefaultValue();
	}

	for (int i = 0; i < LocalVariables->size(); i++)
	{
		for (int j = 0; j < Helper::GetElementDeclareVariableNode(LocalVariables, i)->IDs->size(); j++)
		{
			LocalValues[Helper::ToLower(Helper::GetElementString(Helper::GetElementDeclareVariableNode(LocalVariables, i)->IDs,j))] = Helper::GetTypeFromTypeNode(Helper::GetElementParameterNode(Params, i)->Type)->DefaultValue();
		}
	}

	return new Value();
}

FunctionType::FunctionType(Type* type, list<ParameterNode*> *ls, list<DeclareVariableNode*> *local, list<StatementNode*> * Stm)
{
	this->ReturnType = type;
	this->Params = ls;
	this->Name = "function";
	this->LocalVariables = local;
	this->Statements = Stm;
}