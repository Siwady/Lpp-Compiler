#ifndef EXPRESSIONFUNCTIONNODE_H
#define EXPRESSIONFUNCTIONNODE_H
#include <list>
#include "expressionnode.h"
#include "helper.h"
#include "Semantic/Type/functiontype.h"
#include "Semantic/symboltable.h"

using namespace std;
class ExpressionFunctionNode : public ExpressionNode
{
public:
    string ID;
    list<ExpressionNode*> *Expressions;
    ExpressionFunctionNode();
    ExpressionFunctionNode(string id,list<ExpressionNode*> *expressions,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type *ValidateSemantic();
};

#endif // EXPRESSIONFUNCTIONNODE_H
