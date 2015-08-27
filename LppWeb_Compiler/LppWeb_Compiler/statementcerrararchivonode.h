#ifndef STATEMENTCERRARARCHIVONODE_H
#define STATEMENTCERRARARCHIVONODE_H
#include "statementnode.h"
#include "variablenode.h"

class StatementCerrarArchivoNode : public StatementNode
{
public:
    VariableNode* Variable;
    StatementCerrarArchivoNode(VariableNode* var);
};

#endif // STATEMENTCERRARARCHIVONODE_H
