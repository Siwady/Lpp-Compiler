#ifndef ARREGLOTYPE_H
#define ARREGLOTYPE_H
#include "type.h"
#include <list>
using namespace std;

class ArregloType : public Type
{
public:
	~ArregloType() override;
	Value* DefaultValue() override;
	Type *ArrayType;
    list<int>* Dimention;
    ArregloType(Type *type, list<int>* dim);
    ArregloType();

    string GetName() override;
};

#endif // ARREGLOTYPE_H
