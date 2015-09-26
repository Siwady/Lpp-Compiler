#include "boolnode.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/booleanovalue.h"


Value* BoolNode::Interpret()
{
	
	BooleanoValue * b; 
	if (Helper::ToLower(Booolean).compare("verdadero") == 0){
		b = new BooleanoValue(true);
	}
	else
	{
		b = new BooleanoValue(false);
	}
	return b;
}

BoolNode::~BoolNode()
{
}

BoolNode::BoolNode(string boolean, int row, int column)
{
    this->Booolean=boolean;
    this->Row=row;
    this->Column=column;
    this->NameType="Booleano";
}



string BoolNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Booleano>\n";
    re+=Helper::GetIdentation(i)+Booolean+"\n";
    re+=Helper::GetIdentation(i)+"</Booleano>\n";

    return re ;
}

Type *BoolNode::ValidateSemantic()
{
    BooleanType * b=new BooleanType();
    return b;
}

