// LppWeb_Compiler.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <fstream>
#include "lexer.h"
#include "parser.h"
#include <typeinfo>


int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		std::ifstream myCode("C:/Users/ESiwady/Documents/UNITEC/CompiladoresI/Lpp-Compiler/Compiler_Project/Code.txt");
		std::string code((std::istreambuf_iterator<char>(myCode)), (std::istreambuf_iterator<char>()));
		Lexer* lex = new Lexer(code);
		
		ExpressionNode * b = new EnteroNode(10);
		cout << typeid(b).;
		Parser* parser = new Parser(lex); 
		list<ProgramCodeNode *> *pars=parser->Parse();
		
		ProgramCodeNode  s = **pars->begin();
	

		/*Token *currentToken = lex->GetToken();

		while (currentToken->Type != Eof)
		{
		cout<<currentToken->ToString()<<"\n";
		currentToken = lex->GetToken();
		}
		std::cout<<currentToken->ToString()<<"\n";*/

		cout << "Parser Works!!!";
		cin.get();
	}
	catch (LexicalException& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	catch (ParserException& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
		cin.get();
	}
	return 0;
}

