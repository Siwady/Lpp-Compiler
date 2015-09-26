#include "sumnode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/type.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/realvalue.h"
#include "../../../Interpret/Values/enterovalue.h"
#include "../../../Interpret/Values/cadenavalue.h"

SumNode::~SumNode()
{
	delete LeftNode;
	delete RightNode;
}

::Value* SumNode::Interpret()
{
	Value* leftNode = LeftNode->Interpret();
	Value* righNode = RightNode->Interpret();


	if (leftNode->Name.compare("Entero") == 0 && righNode->Name.compare("Entero") == 0)
	{
		int l = (dynamic_cast<EnteroValue*>(leftNode))->value;
		int r = (dynamic_cast<EnteroValue*>(righNode))->value;
		EnteroValue * v = new EnteroValue(l + r);
		return v;
	}
	else if (leftNode->Name.compare("Entero") == 0 && righNode->Name.compare("Real") == 0)
	{
		int l = (dynamic_cast<EnteroValue*>(leftNode))->value;
		float r = (dynamic_cast<RealValue*>(righNode))->value;
		RealValue * v = new RealValue(l + r);
		return v;
	}
	else if (leftNode->Name.compare("Real") == 0 && righNode->Name.compare("Entero") == 0)
	{
		float l = (dynamic_cast<RealValue*>(leftNode))->value;
		int r = (dynamic_cast<EnteroValue*>(righNode))->value;
		RealValue * v = new RealValue(l + r);
		return v;
	}
	else if (leftNode->Name.compare("Cadena") == 0 && righNode->Name.compare("Cadena") == 0)
	{
		string l = (dynamic_cast<CadenaValue*>(leftNode))->value;
		string  r = (dynamic_cast<CadenaValue*>(righNode))->value;
		CadenaValue * v = new CadenaValue(l + r);
		return v;
	}
	else if (leftNode->Name.compare("Real") == 0 && righNode->Name.compare("Real") == 0)
	{
		float l = (dynamic_cast<RealValue*>(leftNode))->value;
		float r = (dynamic_cast<RealValue*>(righNode))->value;
		RealValue * v = new RealValue(l + r);
		return v;
	}
	else
	{
		throw SemanticException("Tipos de dato incompatibles " + leftNode->Name + "-" + righNode->Name + ",Fila:" + to_string(Row) + ",Columna:" + to_string(Column));
	}
}

SumNode::SumNode(ExpressionNode* left, ExpressionNode* right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string SumNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<SumOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</SumOperation>\n";
    return re;
}


Type *SumNode::ValidateSemantic()
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
    }else if(leftNode->Name.compare("Cadena")==0 && righNode->Name.compare("Cadena")==0)
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
