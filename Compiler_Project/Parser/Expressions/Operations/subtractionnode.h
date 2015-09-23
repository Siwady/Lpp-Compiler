#ifndef SUBTRACTIONNODE_H
#define SUBTRACTIONNODE_H
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
//#include "Semantic/semanticexception.h";

class SubtractionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SubtractionNode(ExpressionNode* left,ExpressionNode* right,int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // SUBTRACTIONNODE_H
