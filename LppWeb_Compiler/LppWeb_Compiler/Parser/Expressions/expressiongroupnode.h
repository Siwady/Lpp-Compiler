#ifndef EXPRESSIONGROUPNODE_H
#define EXPRESSIONGROUPNODE_H
#include "expressionnode.h"
#include <list>
using namespace std;
class ExpressionGroupNode : public ExpressionNode
{
public:
	~ExpressionGroupNode() override;
	Type* ValidateSemantic() override;
	list<ExpressionNode*> *Expressions;
    ExpressionGroupNode();
    ExpressionGroupNode(list<ExpressionNode*> *ls,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // EXPRESSIONGROUPNODE_H
