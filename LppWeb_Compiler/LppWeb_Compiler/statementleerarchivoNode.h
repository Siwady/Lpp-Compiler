#ifndef STATEMENTLEERARCHIVO_H
#define STATEMENTLEERARCHIVO_H
#include "statementnode.h"
#include <list>
#include "variablenode.h"

using namespace std;

class StatementLeerArchivoNode : public StatementNode
{
public:
    list<VariableNode*> *Variables;
    StatementLeerArchivoNode(list<VariableNode*> *var);
};

#endif // STATEMENTLEERARCHIVO_H
