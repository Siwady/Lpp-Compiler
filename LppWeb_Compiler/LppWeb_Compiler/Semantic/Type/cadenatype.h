#ifndef CADENATYPE_H
#define CADENATYPE_H
#include "type.h"
#include <list>
using namespace std;

class CadenaType : public Type
{
public:
	~CadenaType() override;
	Value* DefaultValue() override;
	int Dim;
    CadenaType(int dim);
    CadenaType();

    string GetName() override;
};

#endif // CADENATYPE_H
