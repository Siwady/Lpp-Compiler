#include "statementleerarchivonode.h"
#include "../../helper.h"

StatementLeerArchivoNode::~StatementLeerArchivoNode()
{
	delete Variables;
}

void StatementLeerArchivoNode::Interpret()
{
}

StatementLeerArchivoNode::StatementLeerArchivoNode(list<VariableNode *> *var, int row, int column)
{
    this->Variables=var;
    this->Row=row;
    this->Column=column;
}



string StatementLeerArchivoNode::ToXML(int i)
{
    string re=Helper::GetIdentation(i)+"<StatementLeerArchivo>\n";

    re+=Helper::GetIdentation(i+1)+"<VariableList>\n";
    for(int j=0;j<Variables->size();j++){
        re+=Helper::GetElementVariableNode(Variables,j)->ToXML(i+2);
    }
    re+=Helper::GetIdentation(i+1)+"</VariableList>\n";

    re+=Helper::GetIdentation(i)+"</StatementLeerArchivo>\n";
    return re;
}


void StatementLeerArchivoNode::ValidateSemantic()
{
    list<VariableNode*>::const_iterator iterator;
    VariableNode* temp;
    for (iterator = Variables->begin(); iterator != Variables->end(); ++iterator) {
        temp=*iterator;
        temp->ValidateSemantic();
    }
}
