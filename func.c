#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void pixel_colors(int width, int height, int channels,unsigned char *data){
  
  FILE *hex_file = fopen("./data/hex.txt", "wb");
  int allP = width * height;

  char *buffer = malloc(allP * ((channels == 3 ? 3*2 : 4*2)+2) );
  char *ptr = buffer;
 
    if (channels == 3) {
      for (int i = 0; i < allP; i++) {
      int index = i * channels;
          ptr += sprintf(ptr, "#%02X%02X%02X\n", data[index], data[index + 1], data[index + 2]);
      }
    }else if (channels == 4) {
      for (int i = 0; i < allP; i++) {
      int index = i * channels;
          ptr += sprintf(ptr, "#%02X%02X%02XFF\n", data[index], data[index + 1], data[index + 2]);
      }
    }
  

  fwrite(buffer, 1, ptr - buffer, hex_file);
  free(buffer);
  fclose(hex_file);
}
