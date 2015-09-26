#ifndef CARACTERVALUE_H
#define CARACTERVALUE_H
#include "value.h"


class CaracterValue : public Value
{
public:
	char value;
    CaracterValue(char v);

};

#endif // CARACTERVALUE_H
