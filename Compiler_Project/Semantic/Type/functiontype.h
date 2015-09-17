#ifndef FUNCTIONTYPE_H
#define FUNCTIONTYPE_H
#include "Semantic/Type/type.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
using namespace std;

class FunctionType : public Type
{
public:
    Type* ReturnType;
    list<ExpressionNode*> Params;
    FunctionType(Type* type,list<ExpressionNode*> ls);
};

#endif // FUNCTIONTYPE_H
