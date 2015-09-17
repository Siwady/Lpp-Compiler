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

Type *SymbolTable::GetTypeVariableType(string name)
{
    if (!SymbolTable::Contains(TypeVariables,name))
        throw SemanticException("Type "+name+" doesn't exist");
    return TypeVariables[name];
}

void SymbolTable::DeclareTypeVariable(string name, Type *value)
{
    if(Contains(TypeVariables,name))
        throw SemanticException("Type " + name + " already exist");
    TypeVariables[name] = value;
}
