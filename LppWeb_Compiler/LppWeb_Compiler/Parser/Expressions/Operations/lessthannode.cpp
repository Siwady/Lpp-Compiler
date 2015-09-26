#include "lessthannode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/type.h"
#include "../../../Semantic/Type/booleantype.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/booleanovalue.h"
#include "../../../Interpret/Values/cadenavalue.h"
#include "../../../Interpret/Values/caractervalue.h"
#include "../../../Interpret/Values/realvalue.h"
#include "../../../Interpret/Values/enterovalue.h"

LessThanNode::~LessThanNode()
{
	delete LeftNode;
	delete RightNode;
}

::Value* LessThanNode::Interpret()
{
	Value* leftNode = LeftNode->Interpret();
	Value* righNode = RightNode->Interpret();
	BooleanoValue * b;

	if (leftNode->Name.compare("Entero") == 0 && righNode->Name.compare("Entero") == 0)
	{
		int l = (dynamic_cast<EnteroValue*>(leftNode))->value;
		int r = (dynamic_cast<EnteroValue*>(righNode))->value;
		b = new BooleanoValue(l< r);
		return b;
	}
	else if (leftNode->Name.compare("Entero") == 0 && righNode->Name.compare("Real") == 0)
	{
		int l = (dynamic_cast<EnteroValue*>(leftNode))->value;
		float r = (dynamic_cast<RealValue*>(righNode))->value;
		b = new BooleanoValue(l < r);
		return b;
	}
	else if (leftNode->Name.compare("Real") == 0 && righNode->Name.compare("Entero") == 0)
	{
		float l = (dynamic_cast<RealValue*>(leftNode))->value;
		int r = (dynamic_cast<EnteroValue*>(righNode))->value;
		b = new BooleanoValue(l < r);
		return b;
	}
	else if (leftNode->Name.compare("Caracter") == 0 && righNode->Name.compare("Caracter") == 0)
	{
		char l = (dynamic_cast<CaracterValue*>(leftNode))->value;
		char r = (dynamic_cast<CaracterValue*>(righNode))->value;
		b = new BooleanoValue(l < r);
		return b;
	}
	else if (leftNode->Name.compare("Cadena") == 0 && righNode->Name.compare("Cadena") == 0)
	{
		string l = (dynamic_cast<CadenaValue*>(leftNode))->value;
		string r = (dynamic_cast<CadenaValue*>(righNode))->value;
		b = new BooleanoValue(l < r);
		return b;
	}
	else if (leftNode->Name.compare("Booleano") == 0 && righNode->Name.compare("Booleano") == 0)
	{
		bool l = (dynamic_cast<BooleanoValue*>(leftNode))->value;
		bool r = (dynamic_cast<BooleanoValue*>(righNode))->value;
		b = new BooleanoValue(l < r);
		return b;
	}
	else
	{
		throw SemanticException("Tipos de dato incompatibles " + leftNode->Name + "-" + righNode->Name + ",Fila:" + to_string(Row) + ",Columna:" + to_string(Column));
	}
}

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
