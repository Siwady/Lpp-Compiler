#include "logicalonode.h"
#include "../../../Semantic/Type/booleantype.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/booleanovalue.h"
#include "../../../Interpret/Values/cadenavalue.h"
#include "../../../Interpret/Values/caractervalue.h"
#include "../../../Interpret/Values/realvalue.h"
#include "../../../Interpret/Values/enterovalue.h"

LogicalONode::~LogicalONode()
{
	delete LeftNode;
	delete RightNode;
}

Value* LogicalONode::Interpret()
{
	Value* leftNode = LeftNode->Interpret();
	Value* righNode = RightNode->Interpret();
	BooleanoValue * b;
	
	if (leftNode->Name.compare("Booleano") == 0 && righNode->Name.compare("Booleano") == 0)
	{
		bool l = (dynamic_cast<BooleanoValue*>(leftNode))->value;
		bool r = (dynamic_cast<BooleanoValue*>(righNode))->value;
		b = new BooleanoValue(l || r);
		return b;
	}
	else
	{
		throw SemanticException("Tipos de dato incompatibles " + leftNode->Name + "-" + righNode->Name + ",Fila:" + to_string(Row) + ",Columna:" + to_string(Column));
	}
}

LogicalONode::LogicalONode(ExpressionNode *left, ExpressionNode *right, int row, int column)
{
    this->LeftNode=left;
    this->RightNode=right;
    this->Row=row;
    this->Column=column;
}



string LogicalONode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalONodeOperation>\n";
    re+=LeftNode->ToXML(i+1);
    re+=RightNode->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LogicalONodeOperation>\n";
    return re;
}


Type *LogicalONode::ValidateSemantic()
{
    Type* leftNode=LeftNode->ValidateSemantic();
    Type* righNode=RightNode->ValidateSemantic();
    BooleanType * b=new BooleanType();

     if(leftNode->Name.compare("Booleano")==0 && righNode->Name.compare("Booleano")==0)
    {
        return b;
    }else
    {
       throw SemanticException("Tipos de dato incompatibles "+ leftNode->Name+"-"+righNode->Name+",Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
}
