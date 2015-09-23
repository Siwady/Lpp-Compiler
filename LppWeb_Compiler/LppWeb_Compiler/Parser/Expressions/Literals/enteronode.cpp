#include "enteronode.h"
#include "../../../Semantic/Type/enterotype.h"
#include "../../../helper.h"

EnteroNode::EnteroNode(int entero, int row, int column)
{
    this->Entero=entero;
    this->Row=row;
    this->Column=column;
    this->NameType="Entero";
}



string EnteroNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<Entero>\n";
    re+=Helper::GetIdentation(i+1)+to_string(Entero)+"\n";
    re+=Helper::GetIdentation(i)+"</Entero>\n";

    return re ;
}

Type *EnteroNode::ValidateSemantic()
{
    EnteroType *e=new EnteroType();
    return e;
}


/*Type *EnteroNode::ValidateSemantic()
{
    return InstanceTypeManager::GetEnteroInstance();
}*/
