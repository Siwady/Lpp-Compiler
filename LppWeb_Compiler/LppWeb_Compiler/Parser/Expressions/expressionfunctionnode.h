#ifndef EXPRESSIONFUNCTIONNODE_H
#define EXPRESSIONFUNCTIONNODE_H
#include <list>
#include "expressionnode.h"

using namespace std;
class ExpressionFunctionNode : public ExpressionNode
{
public:
	~ExpressionFunctionNode() override;
	Value* Interpret() override;
	string ID;
    list<ExpressionNode*> *Expressions;
    ExpressionFunctionNode();
    ExpressionFunctionNode(string id,list<ExpressionNode*> *expressions,int row,int column);

    string ToXML(int i) override;

    Type *ValidateSemantic() override;
};

#endif // EXPRESSIONFUNCTIONNODE_H
