#ifndef ARCHIVOTYPE_H
#define ARCHIVOTYPE_H
#include "Semantic/Type/type.h"
#include <list>

using namespace std;

class ArchivoType : public Type
{
public:
    Type *OfType;
    ArchivoType(Type * t);
};

#endif // ARCHIVOTYPE_H
