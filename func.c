#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void pixel_colors(int width, int height, int channels, unsigned char *data) {
  FILE *hex_file = fopen("./data/hex.txt", "wb");
  int allP = width * height;

  // allocate enough memory to hold pixel data  
  char *buffer = malloc(allP * channels * 3);
  int index = 0;
  char *ptr = buffer;
  char hex[] = "0123456789ABCDEF";

  for (int i = 0; i < width; i++) {
    for (int k = 0; k < height; k++) {
      index = (i * height + k) * channels;
      if (channels == 3) {

        *ptr++ = hex[data[i] >> 4];
        *ptr++ = hex[data[i] & 0x0F];

        *ptr++ = hex[data[i+1] >> 4];
        *ptr++ = hex[data[i+1] & 0x0F];

        *ptr++ = hex[data[i+2] >> 4];
        *ptr++ = hex[data[i+2] & 0x0F];

        *ptr++ = '\n';
      } else if (channels == 4) {
        *ptr++ = hex[data[i] >> 4];
        *ptr++ = hex[data[i] & 0x0F];

        *ptr++ = hex[data[i+1] >> 4];
        *ptr++ = hex[data[i+1] & 0x0F];

        *ptr++ = hex[data[i+2] >> 4];
        *ptr++ = hex[data[i+2] & 0x0F];
       
        *ptr++ = hex[data[i+3] >> 4];
        *ptr++ = hex[data[i+3] & 0x0F];
        
        *ptr++ = '\n';

      }
    }
  }
  
  /*
  *ptr++ = data[index];
  *ptr++ = data[index + 1];
  *ptr++ = data[index + 2];
  *ptr++ = 255;
  */

  fwrite(buffer, 1, ptr - buffer, hex_file);
  free(buffer);
  fclose(hex_file);
}

