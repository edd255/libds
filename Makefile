lib=src/str.c
playground=playground.c

all:
	gcc -Wall ${playground} ${lib} -o playground
