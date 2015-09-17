#ifndef STATEMENTREPITANODE_H
#define STATEMENTREPITANODE_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include <list>
#include "helper.h"
#include "Semantic/semanticexception.h"

using namespace std;

class StatementRepitaNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    list<StatementNode*>* Statements;
    StatementRepitaNode(ExpressionNode* expr,list<StatementNode*>* ls,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTREPITANODE_H
