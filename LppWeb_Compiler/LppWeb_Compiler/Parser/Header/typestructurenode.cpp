#include "typestructurenode.h"
#include "../../Semantic/symboltable.h"
#include "../../helper.h"

TypeStructureNode::~TypeStructureNode()
{
	delete Type;
}

void TypeStructureNode::Interpret()
{
}

TypeStructureNode::TypeStructureNode(string id, TypeNode *type, int row, int column)
{
    this->ID=id;
    this->Type=type;
    this->Row=row;
    this->Column=column;
}



string TypeStructureNode::ToXML(int i)
{

    string re=Helper::GetIdentation(i)+"<TypeStructure>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";

    re+=Helper::GetIdentation(i+1)+"</ID>\n";
    re+=Type->ToXML(i+1);

    re+=Helper::GetIdentation(i)+"</TypeStructure>\n";
    return re;
}


void TypeStructureNode::ValidateSemantc()
{
    SymbolTable::GetInstance()->DeclareType(ID,Helper::GetTypeFromTypeNode(Type));
}
