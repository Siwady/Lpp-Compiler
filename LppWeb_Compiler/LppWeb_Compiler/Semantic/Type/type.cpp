#include "type.h"

Type::Type()
{

}

string Type::GetName()
{
    return "";
}

Value* Type::DefaultValue()
{
	return new Value();
}
