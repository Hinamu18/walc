all:
	gcc main.c func.c -o walc -I/usr/include/spng -lspng -lm

Test:
	gcc -O3 -flto -march=native -fopenmp  main.c func.c -o walc -I/usr/include/spng -lspng -lm 
	
	time ./walc ArchTan.png 

op:
	gcc -O2 -g -fno-omit-frame-pointer -march=native main.c func.c -o walc -I/usr/include/spng -lspng -lm

WOW:
	gcc -O3 -flto -march=native main.c func.c -o walc -I/usr/include/spng -lspng -lm

