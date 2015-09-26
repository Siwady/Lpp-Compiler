#ifndef BOOLEANOVALUE_H
#define BOOLEANOVALUE_H
#include "value.h"


class BooleanoValue : public Value
{
public:
	bool value;
    BooleanoValue(bool v);
};

#endif // BOOLEANOVALUE_H
