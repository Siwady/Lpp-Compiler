#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
//#include "Semantic/semanticexception.h";

class MultiplicationNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    MultiplicationNode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // MULTIPLICATIONNODE_H
