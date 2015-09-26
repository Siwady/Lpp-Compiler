#include "negativenumbernode.h"
#include "../../../Semantic/Type/negativenumbertype.h"
#include "../../../helper.h"
#include "../../../Interpret/Values/negativenumbervalue.h"
#include "../../../Interpret/Values/enterovalue.h"

NegativeNumberNode::~NegativeNumberNode()
{
}

Value* NegativeNumberNode::Interpret()
{
	Value * v = new NegativeNumberValue(dynamic_cast<EnteroValue*>(Expression->Interpret())->value);
	return v;
}

NegativeNumberNode::NegativeNumberNode(ExpressionNode *expression, int row, int column)
{
    this->Expression=expression;
    this->Row=row;
    this->Column=column;
    this->NameType="NegativeNumber";
}



string NegativeNumberNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<NegativeNumber>\n";
    re+=Expression->ToXML(i+1);
    re+=Helper::GetIdentation(i)+"</NegativeNumber>\n";
    return re;
}


/*Type *NegativeNumberNode::ValidateSemantic()
{
    return InstanceTypeManager::GetNegativeNumberInstance();
}*/


Type *NegativeNumberNode::ValidateSemantic()
{
    NegativeNumberType * n=new NegativeNumberType(this->Expression);
    return n;
}
