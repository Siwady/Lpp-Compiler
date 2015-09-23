#include "subtractionnode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/type.h"
#include "../../../helper.h"

SubtractionNode::SubtractionNode(ExpressionNode *left, ExpressionNode *right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string SubtractionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SubtractionOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</SubtractionOperation>\n";
    return re;
}


Type *SubtractionNode::ValidateSemantic()
{
    Type* leftNode=LeftNode->ValidateSemantic();
    Type* righNode=RightNode->ValidateSemantic();

    if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Entero")==0)
    {
        return leftNode;
    }else if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Real")==0)
    {
        return righNode;
    }else if(leftNode->Name.compare("Real")==0 && righNode->Name.compare("Entero")==0)
    {
        return leftNode;
	}
	else if (leftNode->Name.compare("Real") == 0 && righNode->Name.compare("Real") == 0)
	{
		return leftNode;
	}
	else
    {
       throw SemanticException("Tipos de dato incompatibles "+ leftNode->Name+"-"+righNode->Name+",Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
}
