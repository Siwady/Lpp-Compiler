#ifndef ARCHIVOTYPE_H
#define ARCHIVOTYPE_H
#include <list>
#include "type.h"

using namespace std;

class ArchivoType : public Type
{
public:
	~ArchivoType() override;
	string GetName() override;
	Type *OfType;
    ArchivoType(Type * t);
};

#endif // ARCHIVOTYPE_H
