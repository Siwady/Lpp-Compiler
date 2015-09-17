#include "parser.h"

Parser::Parser(Lexer *lex)
{
    this->Lex=lex;
    InitializeTypeWords();
    InitializeStatementWords();
    ConsumeToken();
}

void Parser::ConsumeToken()
{
    this->CurrentToken = this->Lex->GetToken();
}

void Parser::InitializeTypeWords()
{
    this->TypeWords.insert(make_pair("entero",entero));
    this->TypeWords.insert(make_pair("real",real));
    this->TypeWords.insert(make_pair("booleano",booleano));
    this->TypeWords.insert(make_pair("caracter",caracter));
    this->TypeWords.insert(make_pair("cadena",cadena));
    this->TypeWords.insert(make_pair("arreglo",arreglo));
    this->TypeWords.insert(make_pair("archivo",archivo));
    this->TypeWords.insert(make_pair("id",Id));
}

void Parser::InitializeStatementWords()
{
    this->StatementWords.insert(make_pair("si",si));
    this->StatementWords.insert(make_pair("mientras",mientras));
    this->StatementWords.insert(make_pair("llamar",llamar));
    this->StatementWords.insert(make_pair("caso",caso));
    this->StatementWords.insert(make_pair("abrir",abrir));
    this->StatementWords.insert(make_pair("escribir",escribir));
    this->StatementWords.insert(make_pair("leer",leer));
    this->StatementWords.insert(make_pair("para",para));
    this->StatementWords.insert(make_pair("repita",repita));
    this->StatementWords.insert(make_pair("id",Id));
    this->StatementWords.insert(make_pair("escriba",escriba));
    this->StatementWords.insert(make_pair("cerrar",cerrar));
    this->StatementWords.insert(make_pair("retorne",retorne));
}


list<ProgramCodeNode*>* Parser::Parse()
{
    list<ProgramCodeNode*>* ls=new list<ProgramCodeNode*>();
    ls=Program_Code(ls);
    if (CurrentToken->Type != Eof)
    {
        throw ParserException(string("Error sintactico,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
    return ls;
}

list<ProgramCodeNode*>* Parser::Program_Code(list<ProgramCodeNode*>* ls)
{
    if(CurrentToken->Type== tipo ||CurrentToken->Type== registro || CurrentToken->Type== procedimiento  ||CurrentToken->Type== funcion ||CurrentToken->Type== Id ||Lex->Contains(StatementWords,Lex->ToLowerCase(CurrentToken->Lexeme))|| CurrentToken->Type==Id ||CurrentToken->Type==declarar)
    {
        ls->push_back(Lpp_Program());
        return Program_Code(ls);

    }else if(CurrentToken->Type==Html)
    {
        HtmlNode* node=new HtmlNode(CurrentToken->Lexeme,CurrentToken->Row,CurrentToken->Column);
        ls->push_back(node);
        ConsumeToken();        
        return Program_Code(ls);
    }else
    {
        return ls;//Epsilon
    }
}

LppProgram* Parser::Lpp_Program()
{
    ProgramHeaderNode* node=Program_Header();
    list<StatementNode*>* ls=new list<StatementNode*>();
    LppProgram* program=new LppProgram(node,Statement_List(ls),node->Row,node->Column);
    return program;
}

ProgramHeaderNode* Parser::Program_Header()
{
    int r=CurrentToken->Row;
    int c=CurrentToken->Column;
    if(CurrentToken->Type==tipo || CurrentToken->Type==registro)
    {
        list<StructureNode*>* ls=new list<StructureNode*>();
        TypeHeaderNode* types= new TypeHeaderNode(Types_List(ls),r,c);
        return types;
    }else if(CurrentToken->Type==declarar)
    {
        list<DeclareVariableNode*>* vars=new list<DeclareVariableNode*>();
        vars=Declare(vars);
        DeclareHeaderNode* decl=new DeclareHeaderNode(vars,r,c);
        return decl;
    }else if(CurrentToken->Type== procedimiento  ||CurrentToken->Type== funcion)
    {
        return Methods_List();
    }else
    {
        ProgramHeaderNode * h=new ProgramHeaderNode();
        return h;//Epsilon
    }
}

list<StructureNode*>* Parser::Types_List(list<StructureNode*>* ls)
{
    if(CurrentToken->Type==tipo || CurrentToken->Type==registro)
    {
       ls->push_back(Types_Structure());
       return Types_List(ls);
    }else
    {
        return ls;//Epsilon
    }
}

StructureNode* Parser::Types_Structure()
{
    if(CurrentToken->Type==tipo)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
       ConsumeToken();
       if(CurrentToken->Type==Id)
       {
           string id=CurrentToken->Lexeme;
           ConsumeToken();
           if(CurrentToken->Type==es)
           {
               ConsumeToken();
               if(Lex->Contains(TypeWords,Lex->ToLowerCase(CurrentToken->Lexeme)) || CurrentToken->Type==Id ||CurrentToken->Type==secuencial)
               {
                    TypeStructureNode* type=new TypeStructureNode(id,Type(),r,c);
                    return type;
               }else{
                   throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
               }
           }else{
               throw ParserException(string("se esperaba ES,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
           }
       }else{
           throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
       }
    }else if(CurrentToken->Type==registro)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            string id=CurrentToken->Lexeme;
            ConsumeToken();
            list<DeclareVariableNode*>* ls=new list<DeclareVariableNode*>();
            ls=Declare(ls);
            if(CurrentToken->Type==fin)
            {
                ConsumeToken();
                if(CurrentToken->Type==registro)
                {
                    ConsumeToken();
                    RegisterStructureNode* reg=new RegisterStructureNode(id,ls,r,c);
                    return reg;
                }else{
                    throw ParserException(string("se esperaba registro,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Tipo o Registro,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

TypeNode *Parser::Type()
{
    if(CurrentToken->Type==cadena)
    {
        ConsumeToken();
        if(CurrentToken->Type==LeftBrackets)
        {
            ConsumeToken();
            if(CurrentToken->Type==Const_entero)
            {
                int size=atoi(CurrentToken->Lexeme.c_str());
                ConsumeToken();
                if(CurrentToken->Type==RightBrackets)
                {
                    ConsumeToken();
                    CadenaTypeNode* type=new CadenaTypeNode(size,CurrentToken->Row,CurrentToken->Column);
                    return type;
                }else{
                    throw ParserException(string("se esperaba ],Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba [,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==arreglo)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        if(CurrentToken->Type==LeftBrackets)
        {
            ConsumeToken();
            if(CurrentToken->Type==Const_entero)
            {
                list<int>* dim=Array_Size();
                if(CurrentToken->Type==RightBrackets)
                {
                    ConsumeToken();
                    if(CurrentToken->Type==de)
                    {
                        ConsumeToken();

                        if(Lex->Contains(TypeWords,Lex->ToLowerCase(CurrentToken->Lexeme))|| CurrentToken->Type==Id)
                        {
                            TypeNode* t=Type();
                            ArrayTypeNode* type=new ArrayTypeNode(t,dim,r,c);
                            return type;
                        }else{
                            throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                        }
                    }else{
                        throw ParserException(string("se esperaba {de},Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                    }
                }else{
                    throw ParserException(string("se esperaba ],Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba [,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==archivo)
    {
        ConsumeToken();
        return Arch_Type();

    }else if(CurrentToken->Type==Id ||CurrentToken->Type==entero ||CurrentToken->Type==real||CurrentToken->Type==booleano|| CurrentToken->Type==caracter)
    {
        SimpeTypeNode* type=new SimpeTypeNode(Lex->ToLowerCase(CurrentToken->Lexeme),CurrentToken->Row,CurrentToken->Column);
        ConsumeToken();
        return type;
    }/*else if(CurrentToken->Type==Op_Sub)
    {
        ConsumeToken();
        Const_Negative();
    }*/else
    {
        throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

TypeNode* Parser::Arch_Type()
{
    if(CurrentToken->Type==de)
    {
        ConsumeToken();
        return Type();

    }else if(CurrentToken->Type==secuencial)
    {
        SimpeTypeNode* type=new SimpeTypeNode("secuencial",CurrentToken->Row,CurrentToken->Column);
        ConsumeToken();
        return type;
    }else
    {
        throw ParserException(string("se esperaba De o Secuencial,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<DeclareVariableNode*>* Parser::Declare(list<DeclareVariableNode*>* ls)
{
    if(CurrentToken->Type==declarar)
    {
        ConsumeToken();
        ls->push_back(Declare_Variables());
        return Declare(ls);
    }else
    {
        return ls;//Epsilon
    }
}

DeclareVariableNode* Parser::Declare_Variables()
{
    return Variables_Group();
}

DeclareVariableNode* Parser::Variables_Group()
{
    if(Lex->Contains(TypeWords,Lex->ToLowerCase(CurrentToken->Lexeme))||CurrentToken->Type==Id)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        TypeNode* type=Type();
        if(CurrentToken->Type==Id)
        {
            list<string>* ids=new list<string>();
            ids->push_back(CurrentToken->Lexeme);
            ConsumeToken();
            ids=ID_List(ids);
            DeclareVariableNode* declare=new DeclareVariableNode(type,ids,r,c);
            return declare;

        }else{
            throw ParserException(string("se esperaba un Id,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba un Tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<string>* Parser::ID_List(list<string>* ls)
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            ls->push_back(CurrentToken->Lexeme);
            ConsumeToken();
            return ID_List(ls);
        }else{
            throw ParserException(string("se esperaba un Id,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        return ls;//Epsilon
    }
}

list<int>* Parser::Array_Size()
{
    if(CurrentToken->Type==Const_entero)
    {
        list<int>* ls=new list<int>();
        ls->push_back(atoi(CurrentToken->Lexeme.c_str()));
        ConsumeToken();

        return Integer_List(ls);
    }else{
        throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<int> *Parser::Integer_List(list<int> * ls)
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        if(CurrentToken->Type==Const_entero)
        {
            ls->push_back(atoi(CurrentToken->Lexeme.c_str()));
            ConsumeToken();

            return Integer_List(ls);
        }else{
            throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        return ls;//Epsilon
    }
}

ProgramHeaderNode *Parser::Methods_List()
{
    if(CurrentToken->Type==procedimiento)
    {
        ConsumeToken();
        ProcedureNode* proc=new ProcedureNode();
        if(CurrentToken->Type==Id)
        {
            list<DeclareVariableNode*>* variables=new list<DeclareVariableNode*>();
            proc->ID=CurrentToken->Lexeme;
            ConsumeToken();
            proc->Params=Params_List();
            proc->Variables=Declare(variables);
            proc->Statements=Method_Body();
            return proc;
            //Methods_List();
        }else{
            throw ParserException(string("se esperaba un ID ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }

    }else if( CurrentToken->Type==funcion)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();

        if(CurrentToken->Type==Id)
        {
            string id=CurrentToken->Lexeme;
            ConsumeToken();
            list<ParameterNode*>* param=Params_List();
            if(CurrentToken->Type==colon)
            {
                ConsumeToken();
                TypeNode* t=Type();
                list<DeclareVariableNode*>* ls=new list<DeclareVariableNode*>();
                ls=Declare(ls);
                list<StatementNode*>* state=Method_Body();
                FunctionNode* func=new FunctionNode(id,param,t,ls,state,r,c);
                return func;
                //Methods_List();
            }else{
                throw ParserException(string("se esperaba :  ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba un ID ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        ProgramHeaderNode *h =new ProgramHeaderNode();
        return h;//Epsilon
    }
}

list<StatementNode *> *Parser::Method_Body()
{
    if(CurrentToken->Type==inicio)
    {
        ConsumeToken();
        list<StatementNode*>* ls=new list<StatementNode*>();
        if(Lex->Contains(StatementWords,Lex->ToLowerCase(CurrentToken->Lexeme))|| CurrentToken->Type==Id)
        {
            ls=Statement_List(ls);
        }else
        {
            //Epsilon
        }
        if(CurrentToken->Type==fin)
        {
            ConsumeToken();
            return ls;
        }else{
            throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Inicio,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

/*void Parser::Function_Body()
{
    if(CurrentToken->Type==inicio)
    {
        ConsumeToken();
        Statement_List();

        if(CurrentToken->Type==retorne)
        {
            ConsumeToken();
            Expression();
            if(CurrentToken->Type==fin)
            {
                ConsumeToken();
            }else{
                throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba Retorne,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }

    }else{
        throw ParserException(string("se esperaba Inicio,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}
*/
list<ParameterNode *> *Parser::Params_List()
{
    list<ParameterNode*>* ls=new list<ParameterNode*>();
    if(CurrentToken->Type==LeftParent)
    {
        ConsumeToken();
        ls=Declare_Params();
        if(CurrentToken->Type==RightParent)
        {
            ConsumeToken();
            return ls;
        }else{
           throw ParserException(string("se esperaba ),Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        return ls;//Epsilon
    }
}

list<ParameterNode*>* Parser::Declare_Params()
{
    list<ParameterNode*>* params=new list<ParameterNode*>();
    params->push_back(Param());
    return Param_Group(params);
}

list<ParameterNode *> *Parser::Param_Group(list<ParameterNode*>* ls)
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        ls->push_back(Param());
        return Param_Group(ls);
    }else
    {
        return ls;//Epsilon
    }
}

ParameterNode *Parser::Param()
{
    if(CurrentToken->Type==var)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        TypeNode* t=Type();
        if(CurrentToken->Type==Id)
        {
            string id=CurrentToken->Lexeme;
            ConsumeToken();
            ParameterNode* param=new ParameterNode(t,id,true,r,c);
            return param;
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(Lex->Contains(TypeWords,Lex->ToLowerCase(CurrentToken->Lexeme))|| CurrentToken->Type==Id)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        TypeNode* t=Type();

        if(CurrentToken->Type==Id)
        {
            string id=CurrentToken->Lexeme;
            ConsumeToken();
            ParameterNode* param=new ParameterNode(t,id,false,r,c);
            return param;
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba var o un Tipo de dato,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}


list<StatementNode *> *Parser::Statement_List(list<StatementNode *> * sl)
{
    if(Lex->Contains(StatementWords,Lex->ToLowerCase(CurrentToken->Lexeme))|| CurrentToken->Type==Id)
    {
        sl->push_back(Statement());
        sl=Statement_List(sl);
        return sl;
    }else
    {
        return sl;//Epsilon
    }
}

StatementNode *Parser::Statement()
{
    if(CurrentToken->Type==si)
    {
        return Statement_Si();
    }else if(CurrentToken->Type==mientras)
    {
        return Statement_Mientras();
    }else if(CurrentToken->Type==llamar)
    {
        return Statement_Llamar();
    }else if(CurrentToken->Type==caso)
    {
        return Statement_Case();
    }else if(CurrentToken->Type==abrir)
    {
        return Statement_Abrir_Archivo();
    }else if(CurrentToken->Type==escribir)
    {
        return Statement_Escribir_Archivo();
    }else if(CurrentToken->Type==leer)
    {
        return Statement_Leer_Archivo();
    }else if(CurrentToken->Type==para)
    {
        return Statement_Para();
    }else if(CurrentToken->Type==repita)
    {
        return Statement_Repita();
    }else if(CurrentToken->Type==Id)
    {
       return  Statement_Assignment();
    }else if(CurrentToken->Type==escriba)
    {
        return Statement_Escriba();
    }else if(CurrentToken->Type==cerrar)
    {
        return Statement_Cerrar_Archivo();
    }else if(CurrentToken->Type==retorne)
    {
        return Statement_Return();
    }else
    {
        throw ParserException(string("se esperaba una sentencia,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Return()
{
    if(CurrentToken->Type==retorne)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        StatementReturnNode* statement=new StatementReturnNode(Expression(),r,c);
        return statement;
    }else
    {
        throw ParserException(string("se esperaba Retorne,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Si()
{
    if(CurrentToken->Type==si)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        ExpressionNode* e=Expression();

        if(CurrentToken->Type==entonces)
        {
            ConsumeToken();
            list<StatementNode*>* lsSi=new list<StatementNode*>();
            lsSi=Statement_List(lsSi);

            list<StatementNode*>* lsSino=new list<StatementNode*>();
            lsSino=Statement_Sino(lsSino);
            if(CurrentToken->Type==fin)
            {
                ConsumeToken();
                if(CurrentToken->Type==si)
                {
                    StatementSiNode* statement=new StatementSiNode(e,lsSi,lsSino,r,c);
                    ConsumeToken();
                    return statement;
                }else{
                    throw ParserException(string("se esperaba si,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba entonces,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Si ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<StatementNode*>* Parser::Statement_Sino(list<StatementNode*>* ls)
{
    if(CurrentToken->Type==sino)
    {
        ConsumeToken();
        return Statement_List(ls);//Statement_SinoP(ls);
    }else
    {
        return ls;//Epsilon
    }
}

/*list<StatementNode *> *Parser::Statement_SinoP(list<StatementNode*>* ls)
{
    if(CurrentToken->Type==si)
    {
        Statement_Si();
    }else
    {
        Statement_List();
    }
}
*/
StatementNode *Parser::Statement_Para()
{
    if(CurrentToken->Type==para)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        VariableNode* var=Variable();
        if(CurrentToken->Type==Op_Assignment)
        {
            ConsumeToken();
            ExpressionNode* first=Expression();
            if(CurrentToken->Type==hasta)
            {
                ConsumeToken();
                ExpressionNode* second=Expression();
                if(CurrentToken->Type==haga)
                {
                    ConsumeToken();
                    list<StatementNode*>* ls=new list<StatementNode*>();
                    StatementParaNode* statement=new StatementParaNode(var,first,second,Statement_List(ls),r,c);
                    if(CurrentToken->Type==fin)
                    {
                        ConsumeToken();
                        if(CurrentToken->Type==para)
                        {
                            ConsumeToken();
                            return statement;
                        }else{
                            throw ParserException(string("se esperaba Para,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                        }
                    }else{
                        throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                    }
                }else{
                    throw ParserException(string("se esperaba Haga,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba Hasta,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba <-,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba un Para ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

VariableNode* Parser::Variable()
{
    VariableNode* e=Simple_Variable();
    return Compuest_Variable(e);
}

VariableNode* Parser::Simple_Variable()
{
    if(CurrentToken->Type==Id)
    {
        string id=CurrentToken->Lexeme;
        ConsumeToken();
        return Array_Variable(id);
    }else
    {
        throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

VariableNode *Parser::Compuest_Variable(VariableNode* expressionNode)
{

    if(CurrentToken->Type==dot)
    {
        ConsumeToken();
        VariableNode* e=Variable();
        RegisterVariableNode* reg=new RegisterVariableNode(expressionNode,e,CurrentToken->Row,CurrentToken->Column);
        return reg;
    }else
    {
        return expressionNode;//Epsilon
    }
}

VariableNode* Parser::Array_Variable(string id)
{
    if(CurrentToken->Type==LeftBrackets)
    {
        ConsumeToken();

        ArrayVariableNode* arr=new ArrayVariableNode(Expression_List(),id,CurrentToken->Row,CurrentToken->Column);
        if(CurrentToken->Type==RightBrackets)
        {
            ConsumeToken();
            return arr;
        }else
        {
            throw ParserException(string("se esperaba ],Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        SimpleVariableNode *e =new SimpleVariableNode(id,CurrentToken->Row,CurrentToken->Column);
        return e;
        //Epsilon
    }
}

list<ExpressionNode *> *Parser::Expression_List()
{
    if(CurrentToken->Type==Id ||CurrentToken->Type==Const_entero||CurrentToken->Type==Op_Sub || CurrentToken->Type==Const_cadena || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_real ||CurrentToken->Type==verdadero ||CurrentToken->Type==falso ||CurrentToken->Type==LeftParent || CurrentToken->Type==no)
    {
        ExpressionNode* e=Expression();
        list<ExpressionNode*> *ls=new list<ExpressionNode*>();
        ls->push_back(e);
        ls=Expression_Group(ls);
        return ls;
    }else
    {
        throw ParserException(string("se esperaba una expresion,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<ExpressionNode *> *Parser::Expression_ListFunctions(string id)
{
    list<ExpressionNode*> *lst=new list<ExpressionNode*>();
    if(CurrentToken->Type==Id ||CurrentToken->Type==Const_entero||CurrentToken->Type==Op_Sub || CurrentToken->Type==Const_cadena || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_real ||CurrentToken->Type==verdadero ||CurrentToken->Type==falso ||CurrentToken->Type==LeftParent || CurrentToken->Type==no)
    {
        ExpressionNode* e=Expression();

        lst->push_back(e);
        lst=Expression_Group(lst);
        return lst;
    }else
    {
        return lst;//throw ParserException(string("se esperaba una expresion,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<ExpressionNode *> *Parser::Expression_Group(list<ExpressionNode *> *ls)
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        ExpressionNode* e=Expression();
        ls->push_back(e);
        ls=Expression_Group(ls);
        return ls;
    }else
    {
        return ls;//Epsilon
    }
}

StatementNode *Parser::Statement_Mientras()
{
    if(CurrentToken->Type==mientras)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        ExpressionNode* expr=Expression();
        if(CurrentToken->Type==haga)
        {
            ConsumeToken();
            list<StatementNode*>* ls= new list<StatementNode*>();
            ls=Statement_List(ls);
            if(CurrentToken->Type==fin)
            {
                ConsumeToken();
                if(CurrentToken->Type==mientras)
                {
                    ConsumeToken();
                    StatementMientrasNode* statement=new StatementMientrasNode(expr,ls,r,c);
                    return statement;
                }else
                {
                    throw ParserException(string("se esperaba Mientras,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else
            {
                throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else
        {
            throw ParserException(string("se esperaba Haga,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Mientras,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Repita()
{
    if(CurrentToken->Type==repita)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        list<StatementNode*>* ls=new list<StatementNode*>();
        ls=Statement_List(ls);
        if(CurrentToken->Type==hasta)
        {
            ConsumeToken();
            StatementRepitaNode* statement=new StatementRepitaNode(Expression(),ls,r,c);
            return statement;
        }else
        {
            throw ParserException(string("se esperaba Hasta,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Repita,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Llamar()
{
    if(CurrentToken->Type==llamar)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            string id=CurrentToken->Lexeme;
            ConsumeToken();
            if(CurrentToken->Type==LeftParent)
            {
                ConsumeToken();
                list<ExpressionNode*>* ls=Expression_List();
                if(CurrentToken->Type==RightParent)
                {
                    ConsumeToken();
                    StatementLlamarNode* statement=new StatementLlamarNode(id,ls,r,c);
                    return statement;
                }else
                {
                    throw ParserException(string("se esperaba un ),Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else
            {
                throw ParserException(string("se esperaba un (,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else
        {
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Llamar,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Assignment()
{
    if(CurrentToken->Type==Id)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        VariableNode* var=Variable();
        if(CurrentToken->Type==Op_Assignment)
        {
            ConsumeToken();
            StatementAssignmentNode* statement=new StatementAssignmentNode(var,Expression(),r,c);
            return statement;
        }else
        {
            throw ParserException(string("se esperaba <-,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode* Parser::Statement_Case()
{
    if(CurrentToken->Type==caso)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        VariableNode* var=Variable();
        list<CaseNode*>* ls=new list<CaseNode*>();
        list<StatementNode*>* statelist=new list<StatementNode*>();
        ls=Case_List();
        statelist=Sino_Case();
        if(CurrentToken->Type==fin)
        {
            ConsumeToken();
            if(CurrentToken->Type==caso)
            {
                ConsumeToken();
                StatementCasoNode* statement=new StatementCasoNode(var,ls,statelist,r,c);
                return statement;
            }else
            {
                throw ParserException(string("se esperaba Caso,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else
        {
            throw ParserException(string("se esperaba Fin Caso,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Caso,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<CaseNode*>* Parser::Case_List()
{
    list<CaseNode*>* ls=new list<CaseNode*>();
    ls->push_back(Define_Case());
    return Case_Group(ls);
}

CaseNode* Parser::Define_Case()
{
    list<LiteralNode*>* literals=new list<LiteralNode*>();
    int r=CurrentToken->Row;
    int c=CurrentToken->Column;
    literals=Literal_List();
    if(CurrentToken->Type==colon)
    {
        ConsumeToken();
        list<StatementNode*>* ls=new list<StatementNode*>();
        CaseNode* casenode=new CaseNode(literals,Statement_List(ls),r,c);
        return casenode;
    }else
    {
        throw ParserException(string("se esperaba :,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<CaseNode*>* Parser::Case_Group(list<CaseNode*>* ls)
{
    if(CurrentToken->Type==Const_entero ||CurrentToken->Type==Const_real || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_cadena)
    {
        ls->push_back(Define_Case());
        return Case_Group(ls);
    }else
    {
        return ls;//Epsilon
    }
}

list<LiteralNode*>* Parser::Literal_List()
{
    list<LiteralNode*>* ls=new list<LiteralNode*>();
    ls->push_back(Literal());
    return Literal_Group(ls);
}

list<LiteralNode*>* Parser::Literal_Group(list<LiteralNode*>* ls)
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        ls->push_back(Literal());
        return Literal_Group(ls);
    }else
    {
        return ls;//Epsilon
    }
}

LiteralNode* Parser::Literal()
{
    if(CurrentToken->Type==Const_entero ||CurrentToken->Type==Const_real || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_cadena)
    {
        LiteralNode* literal;
        if(CurrentToken->Type==Const_entero)
        {
            literal=new EnteroNode(atoi(CurrentToken->Lexeme.c_str()),CurrentToken->Row,CurrentToken->Column);
        }else if(CurrentToken->Type==Const_real)
        {
            literal=new RealNode(atof(CurrentToken->Lexeme.c_str()),CurrentToken->Row,CurrentToken->Column);
        }else if(CurrentToken->Type==Const_caracter)
        {
            literal=new CaracterNode(CurrentToken->Lexeme.at(1),CurrentToken->Row,CurrentToken->Column);
        }else if(CurrentToken->Type==Const_cadena)
        {
            literal=new CadenaNode(CurrentToken->Lexeme,CurrentToken->Row,CurrentToken->Column);
        }
        ConsumeToken();
        return literal;
    }else
    {
        throw ParserException(string("se esperaba una Literal,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<StatementNode*>* Parser::Sino_Case()
{
    list<StatementNode*>* ls=new list<StatementNode*>();
    if(CurrentToken->Type==sino)
    {
        ConsumeToken();
        if(CurrentToken->Type==colon)
        {
            ConsumeToken();
            list<StatementNode*>* ls=new list<StatementNode*>();
            return Statement_List(ls);
        }else
        {
            throw ParserException(string("se esperaba :,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        return ls;//Epsilon
    }
}

StatementNode *Parser::Statement_Escriba()
{
    if(CurrentToken->Type==escriba)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        list<ExpressionNode*>*ls=new list<ExpressionNode*>();
        ls=Expression_List();
        StatementEscribaNode* statement=new StatementEscribaNode(ls,r,c);
        return statement;
    }else
    {
        throw ParserException(string("se esperaba Escriba,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Abrir_Archivo()
{
    if(CurrentToken->Type==abrir)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        ExpressionNode* e=Expression();
        if(CurrentToken->Type==como)
        {
            ConsumeToken();
            VariableNode* var=Variable();
            StatementAbrirArchivoNode* statement=new StatementAbrirArchivoNode(e,var,Operation_List(),r,c);
            return statement;
        }else
        {
            throw ParserException(string("se esperaba Como,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        throw ParserException(string("se esperaba Abrir,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<string>* Parser::Operation_List()
{
    list<string>* ls=new list<string>();
    if(CurrentToken->Type==para)
    {
        ConsumeToken();

        ls->push_back(Operation());
        string o=Operation_Group();
        if(o.compare("")!=0)
        {
            ls->push_back(o);
        }
        return ls;

    }else
    {
        return ls;//Epsilon
    }
}

string Parser::Operation_Group()
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        return Operation();

    }else
    {
        return "";//Epsilon
    }
}

string Parser::Operation()
{
    if(CurrentToken->Type==lectura ||CurrentToken->Type==escritura)
    {
        ConsumeToken();
        return Lex->ToLowerCase(CurrentToken->Lexeme);
    }else
    {
        throw ParserException(string("se esperaba Escritura o Lectura,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Cerrar_Archivo()
{
    if(CurrentToken->Type==cerrar)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        VariableNode* var=Variable();
        StatementCerrarArchivoNode* statement=new StatementCerrarArchivoNode(var,r,c);
        return statement;
    }else
    {
        throw ParserException(string("se esperaba Cerrar,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode* Parser::Statement_Escribir_Archivo()
{
    if(CurrentToken->Type==escribir)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        list<ExpressionNode*>* exprs=new list<ExpressionNode*>();
        ExpressionNode* e=Expression();
        if(CurrentToken->Type==comma)
        {
            ConsumeToken();
            exprs=Expression_List();
        }else
        {
            throw ParserException(string("se esperaba , ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
        exprs->push_back(e);
        StatementEscribirArchivoNode* statement=new StatementEscribirArchivoNode(exprs,r,c);
        return statement;
    }else
    {
        throw ParserException(string("se esperaba Escribir,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

StatementNode *Parser::Statement_Leer_Archivo()
{
    if(CurrentToken->Type==leer)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        list<VariableNode*> *vars=new list<VariableNode*>();
        vars->push_back(Variable());
        if(CurrentToken->Type==comma)
        {
            ConsumeToken();

            vars->push_back(Variable());
            vars=Variable_List(vars);
        }else
        {
            throw ParserException(string("se esperaba , ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
        StatementLeerArchivoNode* statement=new StatementLeerArchivoNode(vars,r,c);
        return statement;

    }else
    {
        throw ParserException(string("se esperaba Leer,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

list<VariableNode *> *Parser::Variable_List(list<VariableNode*>* var)
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        VariableNode* v=Variable();
        var->push_back(v);
        Variable_List(var);
        return var;
    }else
    {
        return var;//Epsilon
    }
}

ExpressionNode* Parser::Expression()
{

    if(CurrentToken->Type==Id ||CurrentToken->Type==Const_entero||CurrentToken->Type==Op_Sub || CurrentToken->Type==Const_cadena || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_real ||CurrentToken->Type==verdadero ||CurrentToken->Type==falso ||CurrentToken->Type==LeftParent|| CurrentToken->Type==no)
    {
        ExpressionNode* e=Bool_Expression();
        return ExpressionP(e);
    }else
    {
        throw ParserException(string("se esperaba una expresion,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}
ExpressionNode *Parser::ExpressionP(ExpressionNode *node)
{
    int r=CurrentToken->Row;
    int c=CurrentToken->Column;
    if(CurrentToken->Type==Op_LogicalY)
    {
        ConsumeToken();
        ExpressionNode* e=Bool_Expression();
        LogicalYNode* log= new LogicalYNode(node,e,r,c);
        return ExpressionP(log);
    }else if(CurrentToken->Type==Op_LogicalO)
    {
        ConsumeToken();
        ExpressionNode* e=Bool_Expression();
        LogicalONode* logo=new LogicalONode(node,e,r,c);
        return ExpressionP(logo);
    }else
    {
        return node;//Epsilon
    }
}

ExpressionNode *Parser::Bool_Expression()
{
    ExpressionNode* e=Basic_Expression();
    return Bool_ExpressionP(e);
}

ExpressionNode *Parser::Bool_ExpressionP(ExpressionNode* node)
{
    int r=CurrentToken->Row;
    int c=CurrentToken->Column;
    if(CurrentToken->Type==Op_LessThan)
    {
        ConsumeToken();
        ExpressionNode* e=Basic_Expression();
        LessThanNode* less=new LessThanNode(node,e,r,c);
        return Bool_ExpressionP(less);
    }else if(CurrentToken->Type==Op_GreaterThan)
    {
        ConsumeToken();
        ExpressionNode* e=Basic_Expression();
        GreaterThanNode* greater=new GreaterThanNode(node,e,r,c);
        return Bool_ExpressionP(greater);
    }else if(CurrentToken->Type==Op_LessOrEqualThan)
    {
        ConsumeToken();
        ExpressionNode* e=Basic_Expression();
        LessAndEqualThanNode* lesE=new LessAndEqualThanNode(node,e,r,c);
        return Bool_ExpressionP(lesE);
    }else if(CurrentToken->Type==Op_GreaterOrEqualThan)
    {
        ConsumeToken();
        ExpressionNode* e=Basic_Expression();
        GreaterAndEqualThanNode* greE=new GreaterAndEqualThanNode(node,e,r,c);
        return Bool_ExpressionP(greE);
    }else if(CurrentToken->Type==Equal)
    {
        ConsumeToken();
        ExpressionNode* e=Basic_Expression();
        EqualNode* equal=new EqualNode(node,e,r,c);
        return Bool_ExpressionP(equal);
    }else if(CurrentToken->Type==Op_NotEqual)
    {
        ConsumeToken();
        ExpressionNode* e=Basic_Expression();
        NotEqualNode* nEqual=new NotEqualNode(node,e,r,c);
        return Bool_ExpressionP(nEqual);
    }else
    {
        return node;//Epsilon
    }
}

ExpressionNode *Parser::Basic_Expression()
{
    ExpressionNode* e=Factor();
    return Basic_ExpressionP(e);
}

ExpressionNode *Parser::Basic_ExpressionP(ExpressionNode *node)
{
    int r=CurrentToken->Row;
    int c=CurrentToken->Column;
    if(CurrentToken->Type==Op_Sum)
    {
        ConsumeToken();
        ExpressionNode* e=Factor();
        SumNode* sum=new SumNode(node,e,r,c);
        return Basic_ExpressionP(sum);
    }else if(CurrentToken->Type==Op_Sub)
    {
        ConsumeToken();
        ExpressionNode* e=Factor();
        SubtractionNode* sub=new SubtractionNode(node,e,r,c);
        return Basic_ExpressionP(sub);
    }else
    {
        return node;//Epsilon
    }
}

ExpressionNode *Parser::Factor()
{
    ExpressionNode* e=Exp_Op();
    return FactorP(e);
}

ExpressionNode *Parser::FactorP(ExpressionNode *node)
{
    int r=CurrentToken->Row;
    int c=CurrentToken->Column;
    if(CurrentToken->Type==Op_Mult)
    {
        ConsumeToken();
        ExpressionNode* e=Exp_Op();
        MultiplicationNode* mult=new MultiplicationNode(node,e,r,c);
        return FactorP(mult);
    }else if(CurrentToken->Type==Op_Div)
    {
        ConsumeToken();
        ExpressionNode* e=Exp_Op();
        DivisionNode* div=new DivisionNode(node,e,r,c);
        return FactorP(div);
    }else if(CurrentToken->Type==Div)
    {
        ConsumeToken();
        ExpressionNode* e=Exp_Op();
        IntegerDivisionNode* idiv=new IntegerDivisionNode(node,e,r,c);
        return FactorP(idiv);
    }else if(CurrentToken->Type==mod)
    {
        ConsumeToken();
        ExpressionNode* e=Exp_Op();
        ModNode* mod_node=new ModNode(node,e,r,c);
        return FactorP(mod_node);
    }else
    {
        return node;//Epsilon
    }
}

ExpressionNode *Parser::Exp_Op()
{
    ExpressionNode* e=LogicalNot();
    return Exp_OpP(e);
}

ExpressionNode *Parser::Exp_OpP(ExpressionNode *node)
{
    if(CurrentToken->Type==Op_Exp)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        ExpressionNode* e=LogicalNot();
        ExponentialNode* exp=new ExponentialNode(node,e,r,c);
        return Exp_OpP(exp);
    }else
    {
        return node;//Epsilon
    }
}

ExpressionNode *Parser::LogicalNot()
{
    if(CurrentToken->Type==no)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        LogicalNotNode* ln=new LogicalNotNode(Term(),r,c);
        return ln;
    }else if(CurrentToken->Type==Id || CurrentToken->Type==Const_entero ||CurrentToken->Type==Op_Sub || CurrentToken->Type==Const_cadena || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_real || CurrentToken->Type==verdadero || CurrentToken->Type==falso || CurrentToken->Type==LeftParent)
    {
        return Term();
    }else
    {
        throw ParserException(string("se esperaba un termino,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}


ExpressionNode *Parser::Term()
{
    if(CurrentToken->Type==Id)
    {
        string id=CurrentToken->Lexeme;
        ConsumeToken();
        return Id_Term(id);
    }else if(CurrentToken->Type==LeftParent)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        //Expression();

        list<ExpressionNode*> *ls=Expression_List();
        ExpressionGroupNode *E_group=new ExpressionGroupNode(ls,r,c);
        if(CurrentToken->Type==RightParent)
        {
            ConsumeToken();
            return E_group;
        }else
        {
            throw ParserException(string("se esperaba ) ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==Const_entero || CurrentToken->Type==Const_cadena || CurrentToken->Type==Const_caracter || CurrentToken->Type==Const_real || CurrentToken->Type==verdadero || CurrentToken->Type==falso)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ExpressionNode *e;
        if(CurrentToken->Type==Const_entero)
        {
            e=new EnteroNode(atoi(CurrentToken->Lexeme.c_str()),r,c);
        }else if(CurrentToken->Type==Const_cadena)
        {
            e=new CadenaNode(CurrentToken->Lexeme,r,c);
        }else if(CurrentToken->Type==Const_caracter)
        {
            e=new CaracterNode(CurrentToken->Lexeme.at(1),r,c);
        }else if(CurrentToken->Type==Const_real)
        {
            e=new RealNode(atof(CurrentToken->Lexeme.c_str()),r,c);
        }else if(CurrentToken->Type==verdadero || CurrentToken->Type==falso)
        {
            e=new BoolNode(CurrentToken->Lexeme,r,c);
        }
        ConsumeToken();
        return e;
    }else if(CurrentToken->Type==Op_Sub)
    {
        ConsumeToken();
        return Const_Negative();
    }else
    {
        throw ParserException(string("se esperaba un Factor,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

ExpressionNode *Parser::Id_Term(string id)
{
    if(CurrentToken->Type==LeftParent)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ConsumeToken();
        list<ExpressionNode*> *ls=Expression_ListFunctions(id);
        ExpressionFunctionNode *e= new ExpressionFunctionNode(id,ls,r,c);
        if(CurrentToken->Type==RightParent)
        {
            ConsumeToken();
            return e;
        }else
        {
            throw ParserException(string("se esperaba ) ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==LeftBrackets || CurrentToken->Type==dot)
    {
        return Variable_Factor(id);
    }else
    {
        SimpleVariableNode *id_node=new SimpleVariableNode(id,CurrentToken->Row,CurrentToken->Column);
        return id_node;//Epsilon
    }
}

ExpressionNode *Parser::Variable_Factor(string id)
{
    VariableNode* var1=Array_Variable(id);
    return Compuest_Variable(var1);

}

ExpressionNode *Parser::Const_Negative()
{
    if(CurrentToken->Type==Const_entero || CurrentToken->Type==Const_real || CurrentToken->Type==Id)
    {
        int r=CurrentToken->Row;
        int c=CurrentToken->Column;
        ExpressionNode* e;
        if(CurrentToken->Type==Const_entero)
        {
            e=new EnteroNode(atoi(CurrentToken->Lexeme.c_str()),r,c);
        }else if(CurrentToken->Type==Const_real)
        {
            e=new RealNode(atof(CurrentToken->Lexeme.c_str()),r,c);
        }else
        {
            e=new SimpleVariableNode(CurrentToken->Lexeme,r,c);
        }
        ConsumeToken();
        return e;
    }else if(CurrentToken->Type==LeftParent)
    {
        ConsumeToken();
        ExpressionGroupNode* eg=new ExpressionGroupNode(Expression_List(),CurrentToken->Row,CurrentToken->Column);
        if(CurrentToken->Type==RightParent)
        {
            ConsumeToken();
            return eg;
        }else
        {
            throw ParserException(string("Se esperaba ) ,real, un Id o un ( ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        throw ParserException(string("Tipos de datos incompatibles,real, un Id o un ( ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

