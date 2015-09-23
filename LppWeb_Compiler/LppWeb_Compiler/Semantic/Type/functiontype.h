#ifndef FUNCTIONTYPE_H
#define FUNCTIONTYPE_H
#include <list>
#include "type.h"
#include "../../Parser/Expressions/expressionnode.h"
#include "../../Parser/Statements/parameternode.h"
#include "../../Parser/Expressions/Variables/declarevariablenode.h"
using namespace std;

class FunctionType : public Type
{
public:
    Type* ReturnType;
    list<ParameterNode*>* Params;
	list<DeclareVariableNode*> *LocalVariables;
	FunctionType(Type* type, list<ParameterNode*> *ls, list<DeclareVariableNode*> * local);
};

#endif // FUNCTIONTYPE_H
