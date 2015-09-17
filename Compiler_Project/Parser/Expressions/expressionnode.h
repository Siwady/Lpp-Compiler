#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H
#include <string>
#include "Semantic/Type/type.h"
using namespace std;

class ExpressionNode
{
public:
    ExpressionNode();
    int Column;
    int Row;
    string NameType;
    virtual string ToXML(int i);
    virtual Type* ValidateSemantic();
};

#endif // EXPRESSIONNODE_H
