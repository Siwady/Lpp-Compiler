#ifndef CADENAVALUE_H
#define CADENAVALUE_H
#include "value.h"
#include <string>


class CadenaValue : public Value
{
public:
	std::string value;
	CadenaValue(std::string t);
};

#endif // CADENAVALUE_H
