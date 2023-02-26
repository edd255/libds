CC   := clang
LIB  := src/str.c
MAIN := src/playground.c
OUT  := bin/playground

ERROR_FLAGS    := -Wall -Wpedantic -Wextra -Werror
DEBUG_FLAGS    := -Og -gdwarf-4 -fsanitize=address -fsanitize=undefined
OPT_FLAGS      := -Ofast
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes
MAKEFLAGS      := --jobs=$(shell nproc)

all: debug opt memcheck

debug:
	${CC} ${ERROR_FLAGS} ${DEBUG_FLAGS} ${MAIN} ${LIB} -o ${OUT}_debug

opt:
	${CC} ${ERROR_FLAGS} ${OPT_FLAGS} ${MAIN} ${LIB} -o ${OUT}_opt

memcheck: 
	valgrind ${VALGRIND_FLAGS} ./${OUT}_debug
