#ifndef STATEMENTESCRIBIRARCHIVO_H
#define STATEMENTESCRIBIRARCHIVO_H
#include "statementnode.h"
#include <list>
#include "expressionnode.h"
using namespace std;

class StatementEscribirArchivoNode : public StatementNode
{
public:
    list<ExpressionNode*>* Expressions;
    StatementEscribirArchivoNode(list<ExpressionNode*>* ls);
};

#endif // STATEMENTESCRIBIRARCHIVO_H
