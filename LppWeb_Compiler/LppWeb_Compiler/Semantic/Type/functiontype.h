#ifndef FUNCTIONTYPE_H
#define FUNCTIONTYPE_H
#include <list>
#include "type.h"
#include "../../Parser/Expressions/expressionnode.h"
#include "../../Parser/Statements/parameternode.h"
#include "../../Parser/Expressions/Variables/declarevariablenode.h"
#include "../../Parser/Statements/statementnode.h"
#include <map>
using namespace std;

class FunctionType : public Type
{
public:
	~FunctionType() override;
	string GetName() override;
	Value* DefaultValue() override;
	Type* ReturnType;
    list<ParameterNode*>* Params;
	list<DeclareVariableNode*> *LocalVariables;
	list<StatementNode*> * Statements;
	map<string,Value*> LocalValues;
	FunctionType(Type* type, list<ParameterNode*> *ls, list<DeclareVariableNode*> * local, list<StatementNode*> * Stm);
};

#endif // FUNCTIONTYPE_H
