#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H
#include <string>
class Value;
class Type;
using namespace std;

class ExpressionNode
{
public:
	virtual ~ExpressionNode()
	{
	}

	ExpressionNode();
    int Column;
    int Row;
    string NameType;
    virtual string ToXML(int i);
    virtual Type* ValidateSemantic();
	virtual Value* Interpret();
};

#endif // EXPRESSIONNODE_H
