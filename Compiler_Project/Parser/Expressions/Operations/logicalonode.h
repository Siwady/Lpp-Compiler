#ifndef LOGICALONODE_H
#define LOGICALONODE_H
#include "Parser/Expressions/expressionnode.h"
#include"helper.h"
#include "Semantic/Type/booleantype.h"
//#include "Semantic/semanticexception.h";

class LogicalONode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalONode(ExpressionNode* left,ExpressionNode* right, int row,int column);

    // ExpressionNode interface
public:
    string ToXML(int i);

    // ExpressionNode interface
public:
    Type* ValidateSemantic();
};

#endif // LOGICALONODE_H
