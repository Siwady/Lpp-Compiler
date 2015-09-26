#ifndef ENTEROTYPE_H
#define ENTEROTYPE_H
#include "type.h"

class EnteroType : public Type
{
public:
	~EnteroType() override;
	Value* DefaultValue() override;
	EnteroType();

    string GetName() override;
};

#endif // ENTEROTYPE_H
