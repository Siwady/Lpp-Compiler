#ifndef REGISTERVARIABLETYPE_H
#define REGISTERVARIABLETYPE_H
#include "Semantic/Type/type.h"
#include <list>
#include "Parser/Expressions/Variables/declarevariablenode.h"
using namespace std;

class RegisterVariableType : public Type
{
public:
    list<DeclareVariableNode*>* Attributes;
    RegisterVariableType(list<DeclareVariableNode*> *atr);

    // Type interface
public:
    string GetName();
};

#endif // REGISTERVARIABLETYPE_H
