#ifndef STATEMENTCASONODE_H
#define STATEMENTCASONODE_H
#include "statementnode.h"
#include "statementnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "casenode.h"
#include "Semantic/semanticexception.h"


class StatementCasoNode : public StatementNode
{
public:
    VariableNode* Variable;
    list<CaseNode*>* Cases;
    list<StatementNode*>* SinoCase;
    StatementCasoNode(VariableNode* var,list<CaseNode*>* cases,list<StatementNode*>* sinocase,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);


    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTCASONODE_H
