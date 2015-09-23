#include <QCoreApplication>
#include "Lexer/lexer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Parser/parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        ifstream myCode("C:/Users/ESiwady/Documents/UNITEC/CompiladoresI/Lpp-Compiler/Compiler_Project/Code.txt");
        string code((istreambuf_iterator<char>(myCode) ),(istreambuf_iterator<char>()));
        Lexer* lex=new Lexer(code);

        Parser* parser=new Parser(lex);
        list<ProgramCodeNode*>*ls=parser->Parse();

        for(int i=0;i<ls->size();i++)
        {
            //cout<<Helper::GetElementProgramCodeNode(ls,i)->ToXML(0);
            Helper::GetElementProgramCodeNode(ls,i)->ValidateSemantic();
        }

        /*Token *currentToken = lex->GetToken();

        while (currentToken->Type != Eof)
        {
           cout<<currentToken->ToString()<<"\n";
           currentToken = lex->GetToken();
        }
        std::cout<<currentToken->ToString()<<"\n";*/

        cout<<"Parser Works!!!";
    }catch (LexicalException& e)
    {
        cout << e.what() << '\n';
    }catch (ParserException& e)
    {
        cout << e.what() << '\n';
    }catch (exception& e)
    {
        cout << e.what() << '\n';
    }

    return a.exec();
}
