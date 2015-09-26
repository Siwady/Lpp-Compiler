#include "proceduretype.h"
#include "../../helper.h"

ProcedureType::~ProcedureType()
{
	delete Params;
	delete LocalVariables;
}

string ProcedureType::GetName()
{
	return Name;
}

Value* ProcedureType::DefaultValue()
{
	for (int i = 0; i < Params->size(); i++)
	{
		LocalValues[Helper::ToLower(Helper::GetElementParameterNode(Params, i)->ID)] = Helper::GetTypeFromTypeNode(Helper::GetElementParameterNode(Params, i)->Type)->DefaultValue();
	}

	for (int i = 0; i < LocalVariables->size(); i++)
	{
		for (int j = 0; j < Helper::GetElementDeclareVariableNode(LocalVariables, i)->IDs->size(); j++)
		{
			LocalValues[Helper::ToLower(Helper::GetElementString(Helper::GetElementDeclareVariableNode(LocalVariables, i)->IDs, j))] = Helper::GetTypeFromTypeNode(Helper::GetElementParameterNode(Params, i)->Type)->DefaultValue();
		}
	}

	return new Value();
}

ProcedureType::ProcedureType(list<ParameterNode *> *params, list<DeclareVariableNode*> * local, list<StatementNode*> *stm)
{
    this->Params=params;
	this->Name = "procedure";
	this->LocalVariables = local;
	Statements = stm;
}

