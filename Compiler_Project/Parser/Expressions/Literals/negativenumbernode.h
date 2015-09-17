#ifndef NEGATIVENUMBERNODE_H
#define NEGATIVENUMBERNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/instancetypemanager.h"

class NegativeNumberNode : public ExpressionNode
{
public:
    ExpressionNode* Expression;
    NegativeNumberNode(ExpressionNode* expression,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);


    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // NEGATIVENUMBERNODE_H
