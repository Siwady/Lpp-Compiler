#ifndef EXPRESSIONFUNCTIONNODE_H
#define EXPRESSIONFUNCTIONNODE_H
#include <list>
#include "expressionnode.h"

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
    string ToXML(int i) override;

    // ExpressionNode interface
public:
    Type *ValidateSemantic() override;
};

#endif // EXPRESSIONFUNCTIONNODE_H
