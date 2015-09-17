#ifndef STATEMENTABRIRARCHIVO_H
#define STATEMENTABRIRARCHIVO_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include <string>
#include <list>
#include "helper.h"
#include "Semantic/semanticexception.h"

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
