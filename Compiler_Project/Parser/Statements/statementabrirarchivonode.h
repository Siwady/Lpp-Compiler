#ifndef STATEMENTABRIRARCHIVO_H
#define STATEMENTABRIRARCHIVO_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include <string>
#include <list>
#include "helper.h"

using namespace std;

class StatementAbrirArchivoNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    VariableNode* Variable;
    list<string>* Operators;
    StatementAbrirArchivoNode(ExpressionNode* expr,VariableNode* var,list<string>*op);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTABRIRARCHIVO_H
