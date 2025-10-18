#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <spng.h>

#include "stb_image.h"

void pixel_colors(int width,int height,int channels,unsigned char *data);

int compareStrings(const void *a, const void *b);

void sorting(char **buffer,int numPixels);
