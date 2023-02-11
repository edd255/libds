CC   := clang
LIB  := src/str.c
MAIN := src/playground.c
OUT  := bin/playground

ERROR_FLAGS  := -Wall -Wpedantic -Wextra -Werror
DEBUG_FLAGS  := -Og -g -fsanitize=address -fsanitize=undefined
OPT_FLAGS    := -Ofast

all: debug opt

debug:
	${CC} ${ERROR_FLAGS} ${DEBUG_FLAGS} ${MAIN} ${LIB} -o ${OUT}_debug

opt:
	${CC} ${ERROR_FLAGS} ${OPT_FLAGS} ${MAIN} ${LIB} -o ${OUT}_opt
