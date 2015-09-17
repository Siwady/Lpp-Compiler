#ifndef SEMANTICEXCEPTION_H
#define SEMANTICEXCEPTION_H
#include <iostream>
#include <exception>
using namespace std;

class SemanticException
{
public:
    string Message;
    SemanticException(string message="Lexical Exception") : Message(message) {}

    ~SemanticException() throw () {}
    const char* what() const throw() { return Message.c_str();}
};

#endif // SEMANTICEXCEPTION_H
