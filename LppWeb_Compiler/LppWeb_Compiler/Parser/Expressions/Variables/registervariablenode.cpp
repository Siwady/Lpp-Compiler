#include "registervariablenode.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/value.h"

RegisterVariableNode::~RegisterVariableNode()
{
	delete Variable1;
	delete Variable2;
}

Value* RegisterVariableNode::Interpret()
{
	Value * v = new Value();
	return v;
}

RegisterVariableNode::RegisterVariableNode()
{

}

RegisterVariableNode::RegisterVariableNode(VariableNode *var1, VariableNode *var2, int row, int column)
{
    this->Variable1=var1;
    this->Variable2=var2;
    this->Row=row;
    this->Column=column;
}

string RegisterVariableNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<RegisterVariable>\n";
    re+=Variable1->ToXML(i+1);
    re+=Variable2->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</RegisterVariable>\n";

    return re ;
}


Type *RegisterVariableNode::ValidateSemantic()
{
    /*if(Variable1->NameType.compare("SimpleVariable")==0)
    {

    }
    Type* var2=Variable2->ValidateSemantic();

   /* if(var1->Name.compare(Variable1->NameType)!=0)
    {
        throw SemanticException("Se esperaba una variable simple ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }

    return dynamic_cast<SimpleVariableType*>(IdType)->OfType;*/

    return NULL;
}
