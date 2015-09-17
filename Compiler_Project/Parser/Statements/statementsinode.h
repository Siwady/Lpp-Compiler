#ifndef STATEMENTSINODE_H
#define STATEMENTSINODE_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include "helper.h"
#include "Semantic/semanticexception.h"
using namespace std;

class StatementSiNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* StatementsSi;
    list<StatementNode*>* StatementsSino;
    StatementSiNode(ExpressionNode* expr, list<StatementNode*>* statementSi, list<StatementNode*>* statementsSino,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTSINODE_H
