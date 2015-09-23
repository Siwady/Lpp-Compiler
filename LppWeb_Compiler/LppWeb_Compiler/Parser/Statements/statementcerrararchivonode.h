#ifndef STATEMENTCERRARARCHIVONODE_H
#define STATEMENTCERRARARCHIVONODE_H
#include "statementnode.h"
#include "../Expressions/Variables/variablenode.h"

class StatementCerrarArchivoNode : public StatementNode
{
public:
    VariableNode* Variable;
    StatementCerrarArchivoNode(VariableNode* var,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i) override;

    // StatementNode interface
public:
    void ValidateSemantic() override;
};

#endif // STATEMENTCERRARARCHIVONODE_H
