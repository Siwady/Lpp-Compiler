#ifndef CASENODE_H
#define CASENODE_H
#include "Parser/Expressions/Literals/literalnode.h"
#include "statementnode.h"
#include "Semantic/semanticexception.h"
#include "helper.h"

class CaseNode
{
public:
    list<LiteralNode*>* Literals;
    list<StatementNode *> *Statements;
    int Row;
    int Column;
    CaseNode(list<LiteralNode*>* literals,list<StatementNode*>* statement,int row,int column);

    string ToXML(int i);

    Type* ValidateSemantic();
};

#endif // CASENODE_H
