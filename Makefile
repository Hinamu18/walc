all:
	gcc -O3 -g -fno-omit-frame-pointer -march=native main.c Pixel_Fun.c -o test -lspng -lm
