#include "logicalynode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/type.h"
#include "../../../Semantic/Type/booleantype.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/booleanovalue.h"

LogicalYNode::~LogicalYNode()
{
	delete LeftNode;
	delete RightNode;
}

Value* LogicalYNode::Interpret()
{
	Value* leftNode = LeftNode->Interpret();
	Value* righNode = RightNode->Interpret();
	BooleanoValue * b;

	if (leftNode->Name.compare("Booleano") == 0 && righNode->Name.compare("Booleano") == 0)
	{
		bool l = (dynamic_cast<BooleanoValue*>(leftNode))->value;
		bool r = (dynamic_cast<BooleanoValue*>(righNode))->value;
		b = new BooleanoValue(l && r);
		return b;
	}
	else
	{
		throw SemanticException("Tipos de dato incompatibles " + leftNode->Name + "-" + righNode->Name + ",Fila:" + to_string(Row) + ",Columna:" + to_string(Column));
	}
}

LogicalYNode::LogicalYNode(ExpressionNode *left, ExpressionNode *right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string LogicalYNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalYNodeOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LocalYNodeOperation>\n";
    return re;
}


Type *LogicalYNode::ValidateSemantic()
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
