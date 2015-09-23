#include "lessthannode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/type.h"
#include "../../../Semantic/Type/booleantype.h"
#include "../../../helper.h"

LessThanNode::LessThanNode(ExpressionNode *left, ExpressionNode *right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string LessThanNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LessThenOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LessThanOperation>\n";
    return re;
}


Type *LessThanNode::ValidateSemantic()
{
    Type* leftNode=LeftNode->ValidateSemantic();
    Type* righNode=RightNode->ValidateSemantic();
    BooleanType * b=new BooleanType();

    if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Entero")==0)
    {
        return b;
    }else if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Real")==0)
    {
        return b;
    }else if(leftNode->Name.compare("Real")==0 && righNode->Name.compare("Entero")==0)
    {
        return b;
    }else if(leftNode->Name.compare("Caracter")==0 && righNode->Name.compare("Caracter")==0)
    {
        return b;
    }else if(leftNode->Name.compare("Cadena")==0 && righNode->Name.compare("Cadena")==0)
    {
        return b;
    }else if(leftNode->Name.compare("Booleano")==0 && righNode->Name.compare("Booleano")==0)
    {
        return b;
    }else
    {
       throw SemanticException("Tipos de dato incompatibles "+ leftNode->Name+"-"+righNode->Name+",Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
}
