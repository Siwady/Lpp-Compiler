#include "symboltable.h"
#include "Type/proceduretype.h"
#include "../helper.h"
#include "Type/functiontype.h"

SymbolTable* SymbolTable::Instance = 0;
string SymbolTable::InFunction ="";

SymbolTable::SymbolTable()
{

}

bool SymbolTable::Contains(SymbolTable::MapV maps, string lexeme)
{
    auto search=maps.find(lexeme);

    if(search!=maps.end())
    {
        return true;
    }
    return false;
}

SymbolTable *SymbolTable::GetInstance()
{
    if(! Instance)
    {
        Instance = new SymbolTable();
        Instance->TypeVariables["entero"]=new EnteroType();
        Instance->TypeVariables["cadena"]=new CadenaType(0);
        Instance->TypeVariables["caracter"]=new CaracterType();
        Instance->TypeVariables["booleano"]=new BooleanType();
        Instance->TypeVariables["real"]=new RealType();
		Instance->InFunction = "";

        return Instance;
    }
    else
    {
        return Instance;
    }
}

Type *SymbolTable::GetVariableType(string name)
{
	if (SymbolTable::Contains(Variables, name))
	{
		return Variables[name];
	}
	else if (SymbolTable::Contains(FunctionVariables,InFunction))
	{
		if (Helper::ToLower(FunctionVariables[InFunction]->Name).compare("procedure")==0)
		{
			ProcedureType* type = dynamic_cast<ProcedureType*>(FunctionVariables[InFunction]);
			for (int j = 0; j < type->Params->size();j++)
			{
				if (Helper::ToLower(Helper::GetElementParameterNode(type->Params, j)->ID).compare(Helper::ToLower(name))==0)
				{
					return Helper::GetTypeFromTypeNode(Helper::GetElementParameterNode(type->Params, j)->Type);
				}
			}

			for (int k = 0; k < type->LocalVariables->size(); k++)
			{
				for (int x = 0; x < Helper::GetElementDeclareVariableNode(type->LocalVariables, k)->IDs->size(); x++)
				{
					if (Helper::ToLower(Helper::GetElementString(Helper::GetElementDeclareVariableNode(type->LocalVariables, k)->IDs, x)).compare(Helper::ToLower(name)) == 0)
					{
						return Helper::GetTypeFromTypeNode(Helper::GetElementDeclareVariableNode(type->LocalVariables, k)->Type);
					}
				}
			}
		}
		else if (Helper::ToLower(FunctionVariables[InFunction]->Name).compare("function")==0)
		{
			FunctionType* type = dynamic_cast<FunctionType*>(FunctionVariables[InFunction]);
			for (int j = 0; j < type->Params->size(); j++)
			{
				if (Helper::ToLower(Helper::GetElementParameterNode(type->Params, j)->ID).compare(Helper::ToLower(name)) == 0)
				{
					return Helper::GetTypeFromTypeNode(Helper::GetElementParameterNode(type->Params, j)->Type);
				}
			}

			for (int k = 0; k < type->LocalVariables->size(); k++)
			{
				for (int x = 0; x < Helper::GetElementDeclareVariableNode(type->LocalVariables, k)->IDs->size(); x++)
				{
					if (Helper::ToLower(Helper::GetElementString(Helper::GetElementDeclareVariableNode(type->LocalVariables, k)->IDs, x)).compare(Helper::ToLower(name)) == 0)
					{
						return Helper::GetTypeFromTypeNode(Helper::GetElementDeclareVariableNode(type->LocalVariables, k)->Type);
					}
				}
			}
			
		}
		else
		{
			throw SemanticException("Variable " + name + " no existe");
		}
	}

	throw SemanticException("Variable " + name + " no existe");
}

void SymbolTable::DeclareVariable(string name, Type *value)
{
    if(Contains(Variables,name))
        throw SemanticException("Variable " + name + " ya existe");
    Variables[name] = value;
}

void SymbolTable::ExistType(string name)
{
    if (!SymbolTable::Contains(TypeVariables,name))
        throw SemanticException("Tipo "+name+" no existe");
}

void SymbolTable::DeclareType(string name, Type *value)
{
    if(Contains(TypeVariables,name))
        throw SemanticException("Tipo " + name + " ya existe");
    TypeVariables[name] = value;
}

Type* SymbolTable::GetFunctionVariableType(string name)
{
	if (!SymbolTable::Contains(FunctionVariables, name))
		throw SemanticException("Function" + name + " no existe");
	return FunctionVariables[name];
}

void SymbolTable::DeclareFunctionVariable(string name, Type* value)
{
	if (Contains(FunctionVariables, name))
		throw SemanticException("Funcion " + name + " ya existe");
	FunctionVariables[name] = value;
}

void SymbolTable::SetInFunction(string Id)
{
	InFunction = Id;
}