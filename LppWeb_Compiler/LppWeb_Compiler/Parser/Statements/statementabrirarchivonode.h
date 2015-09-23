#ifndef STATEMENTABRIRARCHIVO_H
#define STATEMENTABRIRARCHIVO_H
#include "statementnode.h"
#include <string>
#include <list>
#include "../Expressions/expressionnode.h"
#include "../Expressions/Variables/variablenode.h"

using namespace std;

class StatementAbrirArchivoNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    VariableNode* Variable;
    list<string>* Operators;
    StatementAbrirArchivoNode(ExpressionNode* expr,VariableNode* var,list<string>*op,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTABRIRARCHIVO_H
