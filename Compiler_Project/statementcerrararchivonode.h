#ifndef STATEMENTCERRARARCHIVONODE_H
#define STATEMENTCERRARARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "helper.h"

class StatementCerrarArchivoNode : public StatementNode
{
public:
    VariableNode* Variable;
    StatementCerrarArchivoNode(VariableNode* var);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTCERRARARCHIVONODE_H
