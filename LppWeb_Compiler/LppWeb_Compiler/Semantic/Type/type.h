#ifndef TYPE_H
#define TYPE_H
#include <string>
#include "../../Interpret/Values/value.h"
using namespace std;

class Type
{
public:
	virtual ~Type()
	{
	}

	Type();
    string Name;
    virtual string GetName();
	virtual Value* DefaultValue();
};

#endif // TYPE_H
