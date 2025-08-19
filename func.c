#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pixel_colors(int width, int height, int channels, unsigned char *data) {
  FILE *hex_file = fopen("./data/hex.txt", "wb");
  int allp = width * height;

  // * 2 = {R{2} G{2} B{2} if A{2}} 
  int TheSize = allp * (channels * 2 + 1); // 1 = newline
  char hex[] = "0123456789ABCDEF";
  char **thefull=malloc(TheSize/*how Many strings*/ * sizeof(char *)/*string*/);
  char **fullp= thefull;
  for (int i = 0; i < allp; i++) {
    for (int k = 0; k < channels; k++) {
       char hex_byte[3];
      // shafted 4 bits so thats become a lower nibble 
      // 0xF extract the lower nibble
      hex_byte[0]= hex[(data[i * channels + k] >> 4) & 0xF];
      // 0xF extract the lower nibble
      hex_byte[1]= hex[data[i * channels + k] & 0xF];
      hex_byte[2]= '\0';
      
      strcat(fullp[i], hex_byte);
    }
    strcat(fullp[i], "\n");
  }

  /*
  *ptr++ = data[index];
  *ptr++ = data[index + 1];
  *ptr++ = data[index + 2];
  *ptr++ = 255;
  */


  for (int i = 0; i < allp; i++) {
    fputs(thefull[i], hex_file);
    free(thefull[i]);
  }
  free(thefull);  
  fclose(hex_file);
}

