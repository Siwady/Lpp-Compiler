#ifndef BOOLNODE_H
#define BOOLNODE_H
#include <string>
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/instancetypemanager.h"

using namespace std;

class BoolNode : public ExpressionNode
{
public:
    string Booolean;
    BoolNode(string boolean,int row,int column);

    string ToXML(int i);

    Type *ValidateSemantic();
};

#endif // BOOLNODE_H
