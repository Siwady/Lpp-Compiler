#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include "Type/enterotype.h"
#include "Type/cadenatype.h"
#include "Type/caractertype.h"
#include "Type/booleantype.h"
#include "Type/realtype.h"
#include "semanticexception.h"
#include "Type/type.h"

using namespace std;

class SymbolTable
{
private:
    typedef map<string,Type*> MapV;
    static SymbolTable *Instance;
	static string InFunction;
    MapV Variables;
    MapV TypeVariables;
	MapV FunctionVariables;
    SymbolTable();
public:
    bool Contains(MapV maps, string lexeme);
    static SymbolTable* GetInstance();
	Type *GetVariableType(string name);
    void DeclareVariable(string name,Type *value);
    void ExistType(string name);
    void DeclareType(string name,Type *value);
	Type *GetFunctionVariableType(string name);
	void DeclareFunctionVariable(string name, Type *value);
	static void SetInFunction(string Id);
};

#endif // SYMBOLTABLE_H
