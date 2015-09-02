#ifndef STATEMENTLEERARCHIVO_H
#define STATEMENTLEERARCHIVO_H
#include "statementnode.h"
#include <list>
#include "variablenode.h"
#include "helper.h"

using namespace std;

class StatementLeerArchivoNode : public StatementNode
{
public:
    list<VariableNode*> *Variables;
    StatementLeerArchivoNode(list<VariableNode*> *var);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTLEERARCHIVO_H
