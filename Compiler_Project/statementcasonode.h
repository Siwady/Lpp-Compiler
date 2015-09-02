#ifndef STATEMENTCASONODE_H
#define STATEMENTCASONODE_H
#include "statementnode.h"
#include "statementnode.h"
#include "variablenode.h"
#include "casenode.h"


class StatementCasoNode : public StatementNode
{
public:
    VariableNode* Variable;
    list<CaseNode*>* Cases;
    list<StatementNode*>* SinoCase;
    StatementCasoNode(VariableNode* var,list<CaseNode*>* cases,list<StatementNode*>* sinocase);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTCASONODE_H
