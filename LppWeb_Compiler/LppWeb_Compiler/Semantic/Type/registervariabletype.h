#ifndef REGISTERVARIABLETYPE_H
#define REGISTERVARIABLETYPE_H
#include <list>
#include "type.h"
#include "../../Parser/Expressions/Variables/declarevariablenode.h"
using namespace std;

class RegisterVariableType : public Type
{
public:
	~RegisterVariableType() override;
	Value* DefaultValue() override;
	list<DeclareVariableNode*>* Attributes;
    RegisterVariableType(list<DeclareVariableNode*> *atr);

    string GetName() override;
};

#endif // REGISTERVARIABLETYPE_H
