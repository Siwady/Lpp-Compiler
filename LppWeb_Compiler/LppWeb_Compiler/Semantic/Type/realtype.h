#ifndef REALTYPE_H
#define REALTYPE_H
#include "type.h"

class RealType : public Type
{
public:
	~RealType() override;
	Value* DefaultValue() override;
	RealType();

    string GetName() override;
};

#endif // REALTYPE_H
