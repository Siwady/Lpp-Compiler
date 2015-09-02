#ifndef EXPRESSIONFUNCTIONNODE_H
#define EXPRESSIONFUNCTIONNODE_H
#include <list>
#include "expressionnode.h"
#include "helper.h"

using namespace std;
class ExpressionFunctionNode : public ExpressionNode
{
public:
    string ID;
    list<ExpressionNode*> *Expressions;
    ExpressionFunctionNode();
    ExpressionFunctionNode(string id,list<ExpressionNode*> *expressions);


    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // EXPRESSIONFUNCTIONNODE_H
