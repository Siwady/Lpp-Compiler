#include "idnode.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/value.h"

IdNode::~IdNode()
{
}

Value* IdNode::Interpret()
{
	Value* v = new Value();
	return v;
}

IdNode::IdNode(string id, int row, int column)
{
    this->ID=id;
    this->Row=row;
    this->Column=column;
    this->NameType="Id";
}



string IdNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<ID>\n";
    re+=Helper::GetIdentation(i+1)+ID+"\n";
    re+=Helper::GetIdentation(i)+"</ID>\n";

    return re ;
}


/*Type *IdNode::ValidateSemantic()
{
    return NULL;
}*/


Type *IdNode::ValidateSemantic()
{
    return NULL;
}
