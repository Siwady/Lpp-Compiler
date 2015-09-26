#include "procedurenode.h"
#include "../../helper.h"
#include "../../Semantic/symboltable.h"
#include "../../Semantic/Type/proceduretype.h"

ProcedureNode::~ProcedureNode()
{
}

void ProcedureNode::ValidateSemantic()
{
	list<ParameterNode*>::const_iterator iterator;
	ParameterNode* temp;
	for (iterator = Params->begin(); iterator != Params->end(); ++iterator) {
		temp = *iterator;
		temp->ValidateSemantic();
	}
	ProcedureType * t = new ProcedureType(Params, Variables,Statements);
	t->DefaultValue();
	SymbolTable::GetInstance()->DeclareVariable(ID, t);
	SymbolTable::GetInstance()->DeclareFunctionVariable(ID, t);

	list<StatementNode*>::const_iterator iterator2;
	StatementNode* temp2;
	SymbolTable::SetInFunction(ID);

	for (iterator2 = Statements->begin(); iterator2 != Statements->end(); ++iterator2) {
		temp2 = *iterator2;
		temp2->ValidateSemantic();
	}
	SymbolTable::SetInFunction("");
	

}

ProcedureNode::ProcedureNode(string id, list<ParameterNode *> *param, list<DeclareVariableNode *> *vars, list<StatementNode *> *statements, int row, int column)
{
    this->ID=id;
    this->Params=param;
    this->Variables=vars;
    this->Statements=statements;
    this->Row=row;
    this->Column=column;
}

ProcedureNode::ProcedureNode()
{

}



string ProcedureNode::ToXML(int i)
{

    string re=Helper::GetIdentation(i)+"<Procedure>\n";
    re+=Helper::GetIdentation(i+1)+"<ID>\n";
    re+=Helper::GetIdentation(i+2)+ID+"\n";
    re+=Helper::GetIdentation(i+1)+"</ID>\n";

    re+=Helper::GetIdentation(i+1)+"<ParamList>\n";
    for(int j=0;j<Params->size();j++){
        re+=Helper::GetElementParameterNode(Params,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</ParamList>\n";
    re+=Helper::GetIdentation(i+1)+"<DeclareVariableList>\n";
    for(int j=0;j<Params->size();j++){
        re+=Helper::GetElementDeclareVariableNode(Variables,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</DeclareVariableList>\n";

    re+=Helper::GetIdentation(i+1)+"<StatementList>\n";
    for(int j=0;j<Statements->size();j++){
        re+=Helper::GetElementStatementNode(Statements,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</StatementList>\n";

    re+=Helper::GetIdentation(i)+"</Procedure>\n";
    return re;
}
