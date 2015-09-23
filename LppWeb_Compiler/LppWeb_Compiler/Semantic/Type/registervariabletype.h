#ifndef REGISTERVARIABLETYPE_H
#define REGISTERVARIABLETYPE_H
#include <list>
#include "type.h"
#include "../../Parser/Expressions/Variables/declarevariablenode.h"
using namespace std;

class RegisterVariableType : public Type
{
public:
    list<DeclareVariableNode*>* Attributes;
    RegisterVariableType(list<DeclareVariableNode*> *atr);

    // Type interface
public:
    string GetName() override;
};

#endif // REGISTERVARIABLETYPE_H
