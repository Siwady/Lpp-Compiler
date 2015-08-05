#include <QCoreApplication>
#include "lexer.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        ifstream myCode("C:/Users/ESiwady/Documents/UNITEC/CompiladoresI/Lpp-Compiler/Compiler_Project/Code.txt");
        string code((istreambuf_iterator<char>(myCode) ),(istreambuf_iterator<char>()));

        Lexer* lex=new Lexer(code);

        Token *currentToken = lex->GetToken();

        while (currentToken->Type != Eof)
        {
           cout<<currentToken->ToString()<<"\n";
           currentToken = lex->GetToken();
        }
        std::cout<<currentToken->ToString()<<"\n";

    }catch (exception& e)
    {
        cout << e.what() << '\n';
    }catch (LexicalException& e)
    {
        cout << e.what() << '\n';
    }

    return a.exec();
}
