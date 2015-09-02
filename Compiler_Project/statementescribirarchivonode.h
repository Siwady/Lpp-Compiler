#ifndef STATEMENTESCRIBIRARCHIVO_H
#define STATEMENTESCRIBIRARCHIVO_H
#include "statementnode.h"
#include <list>
#include "expressionnode.h"
#include "helper.h"
using namespace std;

class StatementEscribirArchivoNode : public StatementNode
{
public:
    list<ExpressionNode*>* Expressions;
    StatementEscribirArchivoNode(list<ExpressionNode*>* ls);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTESCRIBIRARCHIVO_H
