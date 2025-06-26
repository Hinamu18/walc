#ifndef LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <spng.h>

// lib.h
#define LIB_H

#include "stb_image.h" // just include, no define

typedef struct Pixel{
  uint8_t R;
  uint8_t B;
  uint8_t G;
  uint8_t A;
}Pixel;

void pixel_colors(int width,int height,int channels,unsigned char *data);
void read_img(FILE *meaw);
#endif
