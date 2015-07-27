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
    lexer.cpp \
    token.cpp \
    lexicalexception.cpp

HEADERS += \
    lexer.h \
    token.h \
    lexicalexception.h
