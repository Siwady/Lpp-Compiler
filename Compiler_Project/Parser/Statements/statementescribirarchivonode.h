#ifndef STATEMENTESCRIBIRARCHIVO_H
#define STATEMENTESCRIBIRARCHIVO_H
#include "statementnode.h"
#include <list>
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
using namespace std;

class StatementEscribirArchivoNode : public StatementNode
{
public:
    list<ExpressionNode*>* Expressions;
    StatementEscribirArchivoNode(list<ExpressionNode*>* ls,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTESCRIBIRARCHIVO_H
