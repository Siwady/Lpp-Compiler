#ifndef SIMPETYPENODE_H
#define SIMPETYPENODE_H
#include "typenode.h"
#include <string>
using namespace std;

class SimpeTypeNode : public TypeNode
{
public:
    string Type;
    SimpeTypeNode(string type);
};

#endif // SIMPETYPENODE_H
