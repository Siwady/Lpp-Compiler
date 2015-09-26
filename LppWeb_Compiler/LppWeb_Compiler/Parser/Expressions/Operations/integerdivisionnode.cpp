#include "integerdivisionnode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/booleanovalue.h"
#include "../../../Interpret/Values/enterovalue.h"

IntegerDivisionNode::~IntegerDivisionNode()
{
	delete LeftNode;
	delete RightNode;
}

::Value* IntegerDivisionNode::Interpret()
{
	Value* leftNode = LeftNode->Interpret();
	Value* righNode = RightNode->Interpret();
	EnteroValue * b;

	if (leftNode->Name.compare("Entero") == 0 && righNode->Name.compare("Entero") == 0)
	{
		int l = (dynamic_cast<EnteroValue*>(leftNode))->value;
		int r = (dynamic_cast<EnteroValue*>(righNode))->value;
		b = new EnteroValue(l / r);
		return b;
	}
	else
	{
		throw SemanticException("Tipos de dato incompatibles " + leftNode->Name + "-" + righNode->Name + ",Fila:" + to_string(Row) + ",Columna:" + to_string(Column));
	}
}

IntegerDivisionNode::IntegerDivisionNode(ExpressionNode* left, ExpressionNode* right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string IntegerDivisionNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<DivisionOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</DivisionOperation>\n";
    return re;
}


Type *IntegerDivisionNode::ValidateSemantic()
{
    Type* leftNode=LeftNode->ValidateSemantic();
    Type* righNode=RightNode->ValidateSemantic();

    if(leftNode->Name.compare("Entero")==0 && righNode->Name.compare("Entero")==0)
    {
        return leftNode;
    }else
    {
       throw SemanticException("Se esperaba tipo de dato Entero "+ leftNode->Name+"-"+righNode->Name+",Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
}
