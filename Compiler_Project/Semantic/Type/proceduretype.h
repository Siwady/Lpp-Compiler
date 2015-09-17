#ifndef PROCEDURETYPE_H
#define PROCEDURETYPE_H
#include "Semantic/Type/type.h"
#include <list>
#include "Parser/Expressions/expressionnode.h"
using namespace std;
class ProcedureType : public Type
{
public:
    list<ExpressionNode*> Expressions;
    ProcedureType(list<ExpressionNode*> expressions);
};

#endif // PROCEDURETYPE_H
