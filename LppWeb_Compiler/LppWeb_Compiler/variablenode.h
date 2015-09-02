#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include "expressionnode.h"
#include <string>
#include <typeinfo>

class VariableNode : public ExpressionNode
{
public:
	VariableNode*  var;
    VariableNode();
	
};

#endif // VARIABLENODE_H
