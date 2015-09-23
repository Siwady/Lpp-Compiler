#ifndef CASENODE_H
#define CASENODE_H
#include "statementnode.h"
#include <list>
#include "../Expressions/Literals/literalnode.h"

class Type;

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
