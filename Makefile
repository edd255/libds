lib=src/str.c
playground=playground.c

all:
	gcc -Wall -Wpedantic -Wextra -Werror -fsanitize=address -fsanitize=undefined ${playground} ${lib} -o playground
