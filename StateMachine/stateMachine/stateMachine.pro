#-------------------------------------------------
#
# Project created by QtCreator 2014-07-04T13:18:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

CONFIG   += C++11

TARGET = stateMachine
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
	stateMachine.cpp \
	state.cpp \
	transition.cpp

HEADERS += \
	stateMachine.h \
	state.h \
	defs.h \
	transition.h
