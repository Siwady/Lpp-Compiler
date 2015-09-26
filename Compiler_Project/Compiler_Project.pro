#-------------------------------------------------
#
# Project created by QtCreator 2015-07-22T14:36:53
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Compiler_Project
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    helper.cpp \
    Lexer/lexer.cpp \
    Lexer/lexicalexception.cpp \
    Lexer/token.cpp \
    Parser/Expressions/Literals/boolnode.cpp \
    Parser/Expressions/Literals/cadenanode.cpp \
    Parser/Expressions/Literals/caracternode.cpp \
    Parser/Expressions/Literals/enteronode.cpp \
    Parser/Expressions/Literals/htmlnode.cpp \
    Parser/Expressions/Literals/idnode.cpp \
    Parser/Expressions/Literals/literalnode.cpp \
    Parser/Expressions/Literals/negativenumbernode.cpp \
    Parser/Expressions/Literals/realnode.cpp \
    Parser/Expressions/Operations/divisionnode.cpp \
    Parser/Expressions/Operations/equalnode.cpp \
    Parser/Expressions/Operations/exponentialnode.cpp \
    Parser/Expressions/Operations/greaterandequalthannode.cpp \
    Parser/Expressions/Operations/greaterthannode.cpp \
    Parser/Expressions/Operations/integerdivisionnode.cpp \
    Parser/Expressions/Operations/lessandequalthannode.cpp \
    Parser/Expressions/Operations/lessthannode.cpp \
    Parser/Expressions/Operations/logicalnotnode.cpp \
    Parser/Expressions/Operations/logicalonode.cpp \
    Parser/Expressions/Operations/logicalynode.cpp \
    Parser/Expressions/Operations/modnode.cpp \
    Parser/Expressions/Operations/multiplicationnode.cpp \
    Parser/Expressions/Operations/notequalnode.cpp \
    Parser/Expressions/Operations/subtractionnode.cpp \
    Parser/Expressions/Operations/sumnode.cpp \
    Parser/Expressions/Variables/arrayvariablenode.cpp \
    Parser/Expressions/Variables/declarevariablenode.cpp \
    Parser/Expressions/Variables/registervariablenode.cpp \
    Parser/Expressions/Variables/simplevariablenode.cpp \
    Parser/Expressions/Variables/variablenode.cpp \
    Parser/Expressions/expressionfunctionnode.cpp \
    Parser/Expressions/expressiongroupnode.cpp \
    Parser/Expressions/expressionnode.cpp \
    Parser/Header/archivotypenode.cpp \
    Parser/Header/arraytypenode.cpp \
    Parser/Header/cadenatypenode.cpp \
    Parser/Header/declareheadernode.cpp \
    Parser/Header/programheadernode.cpp \
    Parser/Header/registerstructurenode.cpp \
    Parser/Header/simpetypenode.cpp \
    Parser/Header/structurenode.cpp \
    Parser/Header/typeheadernode.cpp \
    Parser/Header/typenode.cpp \
    Parser/Header/typestructurenode.cpp \
    Parser/Statements/casenode.cpp \
    Parser/Statements/functionnode.cpp \
    Parser/Statements/parameternode.cpp \
    Parser/Statements/procedurenode.cpp \
    Parser/Statements/statementabrirarchivonode.cpp \
    Parser/Statements/statementassignmentnode.cpp \
    Parser/Statements/statementcasonode.cpp \
    Parser/Statements/statementcerrararchivonode.cpp \
    Parser/Statements/statementescribanode.cpp \
    Parser/Statements/statementescribirarchivonode.cpp \
    Parser/Statements/statementleerarchivonode.cpp \
    Parser/Statements/statementllamarnode.cpp \
    Parser/Statements/statementmientrasnode.cpp \
    Parser/Statements/statementnode.cpp \
    Parser/Statements/statementparanode.cpp \
    Parser/Statements/statementrepitanode.cpp \
    Parser/Statements/statementreturnnode.cpp \
    Parser/Statements/statementsinode.cpp \
    Parser/lppprogram.cpp \
    Parser/parser.cpp \
    Parser/parserexception.cpp \
    Parser/programcodenode.cpp \
    Semantic/symboltable.cpp \
    Semantic/Type/type.cpp \
    Semantic/Type/enterotype.cpp \
    Semantic/Type/realtype.cpp \
    Semantic/Type/cadenatype.cpp \
    Semantic/Type/caractertype.cpp \
    Semantic/Type/arreglotype.cpp \
    Semantic/semanticexception.cpp \
    Semantic/Type/booleantype.cpp \
    Semantic/Type/negativenumbertype.cpp \
    Semantic/instancetypemanager.cpp \
    Semantic/Type/literalcadena.cpp \
    Semantic/Type/simplevariabletype.cpp \
    Semantic/Type/registervariabletype.cpp \
    Semantic/Type/functiontype.cpp \
    Semantic/Type/proceduretype.cpp \
    Semantic/Type/archivotype.cpp \
    value.cpp \
    enterovalue.cpp \
    cadenavalue.cpp \
    caractervalue.cpp \
    realvalue.cpp \
    booleanovalue.cpp \
    arreglovalue.cpp \
    negativenumbervalue.cpp

HEADERS += \
    helper.h \
    Lexer/lexer.h \
    Lexer/lexicalexception.h \
    Lexer/token.h \
    Parser/Expressions/Literals/boolnode.h \
    Parser/Expressions/Literals/cadenanode.h \
    Parser/Expressions/Literals/caracternode.h \
    Parser/Expressions/Literals/enteronode.h \
    Parser/Expressions/Literals/htmlnode.h \
    Parser/Expressions/Literals/idnode.h \
    Parser/Expressions/Literals/literalnode.h \
    Parser/Expressions/Literals/negativenumbernode.h \
    Parser/Expressions/Literals/realnode.h \
    Parser/Expressions/Operations/divisionnode.h \
    Parser/Expressions/Operations/equalnode.h \
    Parser/Expressions/Operations/exponentialnode.h \
    Parser/Expressions/Operations/greaterandequalthannode.h \
    Parser/Expressions/Operations/greaterthannode.h \
    Parser/Expressions/Operations/integerdivisionnode.h \
    Parser/Expressions/Operations/lessandequalthannode.h \
    Parser/Expressions/Operations/lessthannode.h \
    Parser/Expressions/Operations/logicalnotnode.h \
    Parser/Expressions/Operations/logicalonode.h \
    Parser/Expressions/Operations/logicalynode.h \
    Parser/Expressions/Operations/modnode.h \
    Parser/Expressions/Operations/multiplicationnode.h \
    Parser/Expressions/Operations/notequalnode.h \
    Parser/Expressions/Operations/subtractionnode.h \
    Parser/Expressions/Operations/sumnode.h \
    Parser/Expressions/Variables/arrayvariablenode.h \
    Parser/Expressions/Variables/declarevariablenode.h \
    Parser/Expressions/Variables/registervariablenode.h \
    Parser/Expressions/Variables/simplevariablenode.h \
    Parser/Expressions/Variables/variablenode.h \
    Parser/Expressions/expressionfunctionnode.h \
    Parser/Expressions/expressiongroupnode.h \
    Parser/Expressions/expressionnode.h \
    Parser/Header/archivotypenode.h \
    Parser/Header/arraytypenode.h \
    Parser/Header/cadenatypenode.h \
    Parser/Header/declareheadernode.h \
    Parser/Header/programheadernode.h \
    Parser/Header/registerstructurenode.h \
    Parser/Header/simpetypenode.h \
    Parser/Header/structurenode.h \
    Parser/Header/typeheadernode.h \
    Parser/Header/typenode.h \
    Parser/Header/typestructurenode.h \
    Parser/Statements/casenode.h \
    Parser/Statements/functionnode.h \
    Parser/Statements/parameternode.h \
    Parser/Statements/procedurenode.h \
    Parser/Statements/statementabrirarchivonode.h \
    Parser/Statements/statementassignmentnode.h \
    Parser/Statements/statementcasonode.h \
    Parser/Statements/statementcerrararchivonode.h \
    Parser/Statements/statementescribanode.h \
    Parser/Statements/statementescribirarchivonode.h \
    Parser/Statements/statementleerarchivonode.h \
    Parser/Statements/statementllamarnode.h \
    Parser/Statements/statementmientrasnode.h \
    Parser/Statements/statementnode.h \
    Parser/Statements/statementparanode.h \
    Parser/Statements/statementrepitanode.h \
    Parser/Statements/statementreturnnode.h \
    Parser/Statements/statementsinode.h \
    Parser/lppprogram.h \
    Parser/parser.h \
    Parser/parserexception.h \
    Parser/programcodenode.h \
    Semantic/symboltable.h \
    Semantic/Type/type.h \
    Semantic/Type/enterotype.h \
    Semantic/Type/realtype.h \
    Semantic/Type/cadenatype.h \
    Semantic/Type/caractertype.h \
    Semantic/Type/arreglotype.h \
    Semantic/semanticexception.h \
    Semantic/Type/booleantype.h \
    Semantic/instancetypemanager.h \
    Semantic/Type/negativenumbertype.h \
    Semantic/Type/literalcadena.h \
    Semantic/Type/simplevariabletype.h \
    Semantic/Type/registervariabletype.h \
    Semantic/Type/functiontype.h \
    Semantic/Type/proceduretype.h \
    Semantic/Type/archivotype.h \
    value.h \
    enterovalue.h \
    cadenavalue.h \
    caractervalue.h \
    realvalue.h \
    booleanovalue.h \
    arreglovalue.h \
    negativenumbervalue.h

