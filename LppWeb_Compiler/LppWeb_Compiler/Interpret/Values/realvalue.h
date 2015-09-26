#ifndef REALVALUE_H
#define REALVALUE_H
#include "value.h"


class RealValue : public Value
{
public:
	float value;
    RealValue(float v);
};

#endif // REALVALUE_H
