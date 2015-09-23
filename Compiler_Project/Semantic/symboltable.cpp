#include "symboltable.h"
SymbolTable* SymbolTable::Instance = 0;

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

        return Instance;
    }
    else
    {
        return Instance;
    }
}


Type *SymbolTable::GetVariableType(string name)
{
    if (!SymbolTable::Contains(Variables,name))
        throw SemanticException("Variable "+name+" doesn't exist");
    return Variables[name];
}

void SymbolTable::DeclareVariable(string name, Type *value)
{
    if(Contains(Variables,name))
        throw SemanticException("Variable " + name + " already exist");
    Variables[name] = value;
}

void SymbolTable::ExistType(string name)
{
    if (!SymbolTable::Contains(TypeVariables,name))
        throw SemanticException("Type "+name+" doesn't exist");
}

void SymbolTable::DeclareType(string name, Type *value)
{
    if(Contains(TypeVariables,name))
        throw SemanticException("Type " + name + " already exist");
    TypeVariables[name] = value;
}
