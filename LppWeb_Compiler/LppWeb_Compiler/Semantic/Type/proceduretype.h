#ifndef PROCEDURETYPE_H
#define PROCEDURETYPE_H
#include <list>
#include "type.h"
#include "../../Parser/Expressions/expressionnode.h"
#include "../../Parser/Statements/parameternode.h"
#include "../../Parser/Expressions/Variables/declarevariablenode.h"
#include "../../Parser/Statements/statementnode.h"
#include <map>
using namespace std;
class ProcedureType : public Type
{
public:
	~ProcedureType() override;
	string GetName() override;
	
	Value* DefaultValue() override;
	list<ParameterNode*> *Params;
	list<DeclareVariableNode*> *LocalVariables;
	list<StatementNode*> *Statements;
	map<string, Value*> LocalValues;
	ProcedureType(list<ParameterNode*> *params, list<DeclareVariableNode*> *local, list<StatementNode*> *stm);
};

#endif // PROCEDURETYPE_H
