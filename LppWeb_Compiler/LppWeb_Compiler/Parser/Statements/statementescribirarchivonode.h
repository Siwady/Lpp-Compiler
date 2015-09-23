#ifndef STATEMENTESCRIBIRARCHIVO_H
#define STATEMENTESCRIBIRARCHIVO_H
#include "statementnode.h"
#include <list>
#include "../Expressions/expressionnode.h"
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
