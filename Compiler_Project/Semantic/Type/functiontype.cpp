#include "functiontype.h"

FunctionType::FunctionType(Type *type, list<ExpressionNode *> ls)
{
    this->ReturnType=type;
    this->Params=ls;
    this->Name="Function";
}

