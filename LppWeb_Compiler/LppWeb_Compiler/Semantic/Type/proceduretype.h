#ifndef PROCEDURETYPE_H
#define PROCEDURETYPE_H
#include <list>
#include "type.h"
#include "../../Parser/Expressions/expressionnode.h"
#include "../../Parser/Statements/parameternode.h"
#include "../../Parser/Expressions/Variables/declarevariablenode.h"
using namespace std;
class ProcedureType : public Type
{
public:
    list<ParameterNode*> *Params;
	list<DeclareVariableNode*> *LocalVariables;
	ProcedureType(list<ParameterNode*> *params, list<DeclareVariableNode*> *local);
};

#endif // PROCEDURETYPE_H
