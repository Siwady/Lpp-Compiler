#include "simpetypenode.h"
#include "../../Semantic/symboltable.h"
#include "../../helper.h"

SimpeTypeNode::~SimpeTypeNode()
{
	
}

void SimpeTypeNode::Interpret()
{
}

SimpeTypeNode::SimpeTypeNode(string type, int row, int column)
{
    this->OfType=type;
    this->Row=row;
    this->Column=column;
}



string SimpeTypeNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SimpleType>\n";
    re+=Helper::GetIdentation(i+2)+OfType+"\n";
    re+=Helper::GetIdentation(i)+"</SimpleType>\n";
    return re;
}


void SimpeTypeNode::ValidateSemantic()
{
    SymbolTable::GetInstance()->ExistType(this->OfType);
}
