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
#include "../Interpret/Values/value.h"

using namespace std;

class SymbolTable
{
private:
    typedef map<string,Type*> MapV;
	typedef map<string, Value*> MapValue;
    static SymbolTable *Instance;
	static string InFunction;
    MapV Variables;
    MapV TypeVariables;
	MapV FunctionVariables;
	MapValue VariablesValue;
	
    SymbolTable();
public:
    bool Contains(MapV maps, string lexeme);
	bool Contains(MapValue maps, string lexeme);
    static SymbolTable* GetInstance();
	Type *GetVariableType(string name);
    void DeclareVariable(string name,Type *value);
    void ExistType(string name);
    void DeclareType(string name,Type *value);
	Type *GetFunctionVariableType(string name);
	void DeclareFunctionVariable(string name, Type *value);
	static void SetInFunction(string Id);
	Value* GetVariableValue(string name);
	void SetVariableValue(string name,Value* value);
	Type *ReturnType;


	Value* ReturnValue;
};

#endif // SYMBOLTABLE_H
