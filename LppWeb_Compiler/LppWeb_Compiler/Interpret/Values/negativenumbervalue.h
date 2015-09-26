#ifndef NEGATIVENUMBERVALUE_H
#define NEGATIVENUMBERVALUE_H
#include "value.h"


class NegativeNumberValue : public Value
{
public:
	float value;
    NegativeNumberValue(int v);
};

#endif // NEGATIVENUMBERVALUE_H
