#ifndef STATEMENTLEERARCHIVO_H
#define STATEMENTLEERARCHIVO_H
#include "statementnode.h"
#include <list>
#include "../Expressions/Variables/variablenode.h"

using namespace std;

class StatementLeerArchivoNode : public StatementNode
{
public:
    list<VariableNode*> *Variables;
    StatementLeerArchivoNode(list<VariableNode*> *var,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTLEERARCHIVO_H
