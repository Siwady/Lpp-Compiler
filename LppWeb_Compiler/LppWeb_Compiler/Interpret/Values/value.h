#ifndef VALUE_H
#define VALUE_H
#include <string>


class Value
{
public:
	virtual ~Value()
	{
	}

	std::string Name;
    Value();
	virtual std::string GetName();
};

#endif // VALUE_H
