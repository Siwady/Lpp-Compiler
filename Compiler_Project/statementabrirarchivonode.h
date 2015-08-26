#ifndef STATEMENTABRIRARCHIVO_H
#define STATEMENTABRIRARCHIVO_H
#include "statementnode.h"
#include "expressionnode.h"
#include "variablenode.h"
#include <string>
#include <list>

using namespace std;

class StatementAbrirArchivoNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    VariableNode* Variable;
    list<string>* Operators;
    StatementAbrirArchivoNode(ExpressionNode* expr,VariableNode* var,list<string>*op);
};

#endif // STATEMENTABRIRARCHIVO_H
