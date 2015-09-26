#include "helper.h"
#include "Interpret/Values/enterovalue.h"
#include "Interpret/Values/realvalue.h"
#include "Interpret/Values/cadenavalue.h"
#include "Interpret/Values/caractervalue.h"
#include "Interpret/Values/booleanovalue.h"

Helper::Helper()
{

}

StatementNode *Helper::GetElementStatementNode(list<StatementNode *> *ls, int i)
{
    list<StatementNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

ExpressionNode *Helper::GetElementExpressionNode(list<ExpressionNode *> *ls, int i)
{
    list<ExpressionNode*>::iterator it = ls->begin();
    for(int j=0; j<i;j++){
        ++it;
    }
    return *it;
}

VariableNode *Helper::GetElementVariableNode(list<VariableNode *> *ls, int i)
{
    list<VariableNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

LiteralNode *Helper::GetElementLiteralNode(list<LiteralNode *> *ls, int i)
{
    list<LiteralNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

StructureNode *Helper::GetElementStructureNode(list<StructureNode *> *ls, int i)
{
    list<StructureNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

DeclareVariableNode *Helper::GetElementDeclareVariableNode(list<DeclareVariableNode *> *ls, int i)
{
    list<DeclareVariableNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

string Helper::GetElementString(list<string> *ls, int i)
{
    list<string>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

int Helper::GetElementInt(list<int> *ls, int i)
{
    list<int>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

ParameterNode *Helper::GetElementParameterNode(list<ParameterNode *> *ls, int i)
{
    list<ParameterNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

CaseNode *Helper::GetElementCaseNode(list<CaseNode *> *ls, int i)
{
    list<CaseNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

ProgramCodeNode *Helper::GetElementProgramCodeNode(list<ProgramCodeNode *> *ls, int i)
{
    list<ProgramCodeNode*>::iterator it = ls->begin();
    for(int j=0; j<i; j++){
        ++it;
    }
    return *it;
}

string Helper::GetIdentation(int i)
{
    string s="";
    for(int j=0;j<i;j++)
    {
        s+="  ";
    }
    return s;
}

Type *Helper::GetTypeFromTypeNode(TypeNode *type)
{
	Type* t = new Type();
    if(Helper::ToLower(type->OfType).compare("entero")==0)
    {
        t=new EnteroType();
    }else if(Helper::ToLower(type->OfType).compare("booleano")==0)
    {
        t=new BooleanType();
    }
	else if (Helper::ToLower(type->OfType).compare("caracter") == 0)
    {
        t=new CaracterType();
	}
	else if (Helper::ToLower(type->OfType).compare("real") == 0)
    {
        t=new RealType();
	}
	else if (Helper::ToLower(type->OfType).compare("cadena") == 0)
    {
        CadenaTypeNode *a=dynamic_cast<CadenaTypeNode*>(type);
        t=new CadenaType(a->Size);
	}
	else if (Helper::ToLower(type->OfType).compare("arreglo") == 0)
    {
        ArrayTypeNode *a=dynamic_cast<ArrayTypeNode*>(type);
        t=new ArregloType(GetTypeFromTypeNode(a->Type),a->Dimentions);
	}
	else if (Helper::ToLower(type->OfType).compare("archivo") == 0)
    {
        ArchivoTypeNode *a=dynamic_cast<ArchivoTypeNode*>(type);
        t=new ArchivoType(Helper::GetTypeFromTypeNode(a->Types));
    }
    return t;
}

string Helper::ToLower(string str)
{
	int i = 0;
	char c;
	string newWord = "";
	while (str[i])
	{
		c = str[i];
		newWord += tolower(c);
		i++;
	}
	return newWord;
}

bool Helper::CompareValues(Value* a, Value* b)
{
	if (Helper::ToLower(a->Name) == "entero")
	{
		EnteroValue* v = dynamic_cast<EnteroValue*>(a);
		if (Helper::ToLower(b->Name) == "entero")
		{
			EnteroValue* v2 = dynamic_cast<EnteroValue*>(b);
			return v->value == v2->value;
		}
		else if (Helper::ToLower(b->Name) == "real")
		{
			RealValue* v2 = dynamic_cast<RealValue*>(b);
			return v->value == v2->value;
		}
	}
	else if (Helper::ToLower(a->Name) == "real")
	{
		RealValue* v = dynamic_cast<RealValue*>(a);
		RealValue* v2 = dynamic_cast<RealValue*>(b);
		return v->value == v2->value;
	}
	else if (Helper::ToLower(a->Name) == "cadena")
	{
		CadenaValue* v = dynamic_cast<CadenaValue*>(a);
		CadenaValue* v2 = dynamic_cast<CadenaValue*>(b);
		return v->value == v2->value;
	}
	else if (Helper::ToLower(a->Name) == "caracter")
	{
		CaracterValue* v = dynamic_cast<CaracterValue*>(a);
		CaracterValue* v2 = dynamic_cast<CaracterValue*>(b);
		return v->value == v2->value;
	}
	else if (Helper::ToLower(a->Name) == "booleano")
	{
		BooleanoValue* v = dynamic_cast<BooleanoValue*>(a);
		BooleanoValue* v2 = dynamic_cast<BooleanoValue*>(b);
		return v->value == v2->value;
	}
}