#ifndef SIMPETYPENODE_H
#define SIMPETYPENODE_H
#include "typenode.h"
#include <string>
using namespace std;

class SimpeTypeNode : public TypeNode
{
public:
	~SimpeTypeNode() override;
	void Interpret() override;
	SimpeTypeNode(string type,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // SIMPETYPENODE_H
