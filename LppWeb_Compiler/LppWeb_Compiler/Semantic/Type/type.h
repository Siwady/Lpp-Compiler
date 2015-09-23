#ifndef TYPE_H
#define TYPE_H
#include <string>
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
};

#endif // TYPE_H
