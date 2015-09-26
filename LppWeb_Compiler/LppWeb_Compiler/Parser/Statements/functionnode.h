#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H
//#include "statementnode.h"
#include "parameternode.h"
#include <list>
#include "../Header/programheadernode.h"
#include "../Expressions/Variables/declarevariablenode.h"
#include "statementnode.h"

//#include "variablenode.h"
//#include "statementnode.h"
//#include "expressionnode.h"
//#include "declarevariablenode.h"
//#include "programheadernode.h"

class FunctionNode : public ProgramHeaderNode
{
public:
	void Interpret() override;
	~FunctionNode() override;
	void ValidateSemantic() override;
	string ID;
    list<ParameterNode*>* Params;
    TypeNode* ReturnType;
    list<DeclareVariableNode*>* Variables;
    list<StatementNode*>* Statements;
    FunctionNode(string id,list<ParameterNode*>* param,TypeNode* type,list<DeclareVariableNode*>* vars,list<StatementNode*>* statements,int row,int column);
    FunctionNode();

    string ToXML(int i);
};

#endif // FUNCTIONNODE_H
