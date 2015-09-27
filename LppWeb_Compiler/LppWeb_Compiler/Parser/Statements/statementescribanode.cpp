#include "statementescribanode.h"
#include "../../helper.h"
#include "../../Interpret/Values/value.h"
#include "../../Interpret/Values/enterovalue.h"
#include "../../Interpret/Values/caractervalue.h"
#include "../../Interpret/Values/booleanovalue.h"
#include "../../Interpret/Values/realvalue.h"
#include "../../Interpret/Values/cadenavalue.h"

StatementEscribaNode::~StatementEscribaNode()
{
	delete Expressions;
}

void StatementEscribaNode::Interpret()
{
	Value* v;
	for (int i = 0; i < Expressions->size();i++)
	{
		v = Helper::GetElementExpressionNode(Expressions, i)->Interpret();
		if (v->Name == "Entero")
		{
			cout<<dynamic_cast<EnteroValue*>(v)->value;
		}else if(v->Name == "Caracter")
		{
			cout << dynamic_cast<CaracterValue*>(v)->value;
		}
		else if (v->Name == "Booleano")
		{
			cout << dynamic_cast<BooleanoValue*>(v)->value;
		}
		else if (v->Name == "Real")
		{
			cout << dynamic_cast<RealValue*>(v)->value;
		}
		else if (v->Name == "Cadena")
		{
			string c = dynamic_cast<CadenaValue*>(v)->value;
			cout << c.erase(0,1).substr(0,c.length()-2);
		}
	}
}

StatementEscribaNode::StatementEscribaNode(list<ExpressionNode *> *expressions, int row, int column)
{
    this->Expressions=expressions;
    this->Row=row;
    this->Column=column;
}



string StatementEscribaNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementEscriba>\n";

    re+=Helper::GetIdentation(i+1)+"<ExpressionList>\n";
    for(int j=0;j<Expressions->size();j++){
        re+=Helper::GetElementExpressionNode(Expressions,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ExpressionList>\n";

    re+=Helper::GetIdentation(i)+"</StatementEscriba>\n";
    return re;
}


void StatementEscribaNode::ValidateSemantic()
{
    list<ExpressionNode*>::const_iterator iterator;
    ExpressionNode* temp;
    for (iterator = Expressions->begin(); iterator != Expressions->end(); ++iterator) {
        temp=*iterator;
        temp->ValidateSemantic();
    }
}
