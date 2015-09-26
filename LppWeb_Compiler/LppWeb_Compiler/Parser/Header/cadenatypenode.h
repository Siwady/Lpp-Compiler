#ifndef CADENATYPENODE_H
#define CADENATYPENODE_H
#include "typenode.h"
#include <string>

using namespace std;
class CadenaTypeNode : public TypeNode
{
public:
	~CadenaTypeNode() override;
	void Interpret() override;
	int Size;
    CadenaTypeNode(int size,int row,int column);

    string ToXML(int i) override;

    void ValidateSemantic() override;
};

#endif // CADENATYPENODE_H
