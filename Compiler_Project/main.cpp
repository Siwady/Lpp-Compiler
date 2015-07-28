#include <QCoreApplication>
#include "lexer.h"
#include <stdio.h>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Lexer* lex=new Lexer("inicio\nfin");

    Token *currentToken = lex->GetToken();
    try
    {
        while (currentToken->Type != Eof)
        {
           cout<<currentToken->ToString()<<"\n";
           currentToken = lex->GetToken();
        }
        std::cout<<currentToken->ToString()<<"\n";

    }catch (LexicalException& e)
    {
        cout << e.what() << '\n';
    }
    return a.exec();
}
