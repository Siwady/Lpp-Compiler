#ifndef ENTEROVALUE_H
#define ENTEROVALUE_H
#include "value.h"


class EnteroValue : public Value
{
public:
	int value;
    EnteroValue(int v);

};

#endif // ENTEROVALUE_H
