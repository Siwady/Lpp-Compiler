#ifndef STATEMENTCERRARARCHIVONODE_H
#define STATEMENTCERRARARCHIVONODE_H
#include "statementnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "helper.h"

class StatementCerrarArchivoNode : public StatementNode
{
public:
    VariableNode* Variable;
    StatementCerrarArchivoNode(VariableNode* var,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTCERRARARCHIVONODE_H
