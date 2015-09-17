#ifndef SIMPETYPENODE_H
#define SIMPETYPENODE_H
#include "typenode.h"
#include <string>
#include "helper.h"
using namespace std;

class SimpeTypeNode : public TypeNode
{
public:
    SimpeTypeNode(string type,int row,int column);

    // TypeNode interface
public:
    string ToXML(int i);
};

#endif // SIMPETYPENODE_H
