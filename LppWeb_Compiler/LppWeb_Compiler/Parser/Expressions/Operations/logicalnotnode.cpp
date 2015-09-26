#include "logicalnotnode.h"
#include "../../../Semantic/semanticexception.h"
#include "../../../Semantic/Type/booleantype.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/booleanovalue.h"

LogicalNotNode::~LogicalNotNode()
{
	delete Expression;
}

Value* LogicalNotNode::Interpret()
{
	BooleanoValue* v = dynamic_cast<BooleanoValue*>(Expression->Interpret());
	v->value = !v->value;
	return v;
}

LogicalNotNode::LogicalNotNode(ExpressionNode *expression, int row, int column)
{
    this->Expression=expression;
    this->Row=row;
    this->Column=column;
}



string LogicalNotNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<LogicalNotOperation>\n";
    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</LogicalNotOperation>\n";
    return re;
}


Type *LogicalNotNode::ValidateSemantic()
{
    BooleanType *b=new BooleanType();
    if(Expression->ValidateSemantic()->Name.compare("Booleano")!=0)
    {
        throw SemanticException("Se esperaba tipo de dato Booleano ,Fila:"+to_string(Row)+",Columna:"+to_string(Column));
    }
    return b;
}
