#include "declarevariablenode.h"
#include "../../../helper.h"
#include "../../../Semantic/symboltable.h"

DeclareVariableNode::DeclareVariableNode(TypeNode *type, list<string> *ids, int row, int column)
{
    this->IDs=ids;
    this->Types=type;
    this->Row=row;
    this->Column=column;
}



string DeclareVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<DeclareVariableNode>\n";
    re+=Types->ToXML(i+1);

    re+=Helper::GetIdentation(i+1)+"<ID List>\n";
    for(int j=0;j<IDs->size();j++){
        re+=Helper::GetIdentation(i+2)+Helper::GetElementString(IDs,j);
    }
    re+=Helper::GetIdentation(i+1)+"</ID List>\n";
    re+=Helper::GetIdentation(i)+"</DeclareVariableNode>\n";

    return re ;
}


void DeclareVariableNode::ValidateSemantic()
{
	list<string>::const_iterator iterator;
	string temp;
	for (iterator = IDs->begin(); iterator != IDs->end(); ++iterator) {
		temp = *iterator;
		Type * t = Helper::GetTypeFromTypeNode(Types);
		if (t->Name == "")
		{
			t->Name = Types->OfType;
		}
		SymbolTable::GetInstance()->ExistType(t->Name);
		SymbolTable::GetInstance()->DeclareVariable(temp, t);
	}
}