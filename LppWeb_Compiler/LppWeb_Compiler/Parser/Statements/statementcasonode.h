#ifndef STATEMENTCASONODE_H
#define STATEMENTCASONODE_H
#include "statementnode.h"
#include "casenode.h"
#include "../Expressions/Variables/variablenode.h"


class StatementCasoNode : public StatementNode
{
public:
    VariableNode* Variable;
    list<CaseNode*>* Cases;
    list<StatementNode*>* SinoCase;
    StatementCasoNode(VariableNode* var,list<CaseNode*>* cases,list<StatementNode*>* sinocase,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i) override;


    // StatementNode interface
public:
    void ValidateSemantic() override;
};

#endif // STATEMENTCASONODE_H
