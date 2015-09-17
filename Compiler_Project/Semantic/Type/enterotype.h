#ifndef ENTEROTYPE_H
#define ENTEROTYPE_H
#include "type.h"

class EnteroType : public Type
{
public:
    EnteroType();

    // Type interface
public:
    string GetName();
};

#endif // ENTEROTYPE_H
