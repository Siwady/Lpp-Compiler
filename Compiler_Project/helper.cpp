#include "helper.h"

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
    Type* t;
    if(type->OfType.compare("entero")==0)
    {
        t=new EnteroType();
    }else if(type->OfType.compare("booleano")==0)
    {
        t=new BooleanType();
    }
    else if(type->OfType.compare("caracter")==0)
    {
        t=new CaracterType();
    }else if(type->OfType.compare("real")==0)
    {
        t=new RealType();
    }else if(type->OfType.compare("cadena")==0)
    {
        CadenaTypeNode *a=dynamic_cast<CadenaTypeNode*>(type);
        t=new CadenaType(a->Size);
    }else if(type->OfType.compare("arreglo")==0)
    {
        ArrayTypeNode *a=dynamic_cast<ArrayTypeNode*>(type);
        t=new ArregloType(GetTypeFromTypeNode(a->Type),a->Dimentions);
    }else if(type->OfType.compare("archivo")==0)
    {
        ArchivoTypeNode *a=dynamic_cast<ArchivoTypeNode*>(type);
        t=new ArchivoType(GetTypeFromTypeNode(a->Types));
    }
    return t;
}

