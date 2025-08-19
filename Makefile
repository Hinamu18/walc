all:
	gcc main.c func.c sorting.c -o walc -I/usr/include/spng -lspng -lm

op:
	gcc -O3 -g -fno-omit-frame-pointer -march=native main.c func.c sorting.c -o walc -I/usr/include/spng -lspng -lm

WOW:
	gcc -O3 -flto -march=native main.c func.c sorting.c -o walc -I/usr/include/spng -lspng -lm

