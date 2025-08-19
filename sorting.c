#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void sorting(char *buffer)
{
  FILE *color= fopen("./data/colors.txt","wb");
  int len = strlen(buffer); 
  char** hex = malloc(sizeof(buffer));
  for (int i=0; i<len; i++) {
    hex[i] += buffer[i];
    hex[i] += buffer[i+1]; 
    hex[i] += buffer[i+2];
    hex[i] += buffer[i+3]; 
    hex[i] += buffer[i+4];
    hex[i] += buffer[i+5]; 
  }
  free(hex);
  fclose(color);
}

