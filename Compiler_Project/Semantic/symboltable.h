#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include "Semantic/Type/type.h"
#include "Semantic/semanticexception.h"
#include "Semantic/Type/arreglotype.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/Type/cadenatype.h"
#include "Semantic/Type/caractertype.h"
#include "Semantic/Type/enterotype.h"
#include "Semantic/Type/realtype.h"
#include "Semantic/Type/negativenumbertype.h"
#include "Semantic/Type/literalcadena.h"
#include "Semantic/Type/archivotype.h"

using namespace std;

class SymbolTable
{
private:
    typedef map<string,Type*> MapV;
    static SymbolTable *Instance;
    MapV Variables;
    MapV TypeVariables;
    SymbolTable();
public:
    bool Contains(MapV maps, string lexeme);
    static SymbolTable* GetInstance();
    Type *GetVariableType(string name);
    void DeclareVariable(string name,Type *value);
    Type *GetTypeVariableType(string name);
    void DeclareTypeVariable(string name,Type *value);
};

#endif // SYMBOLTABLE_H
