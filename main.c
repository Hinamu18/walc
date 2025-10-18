#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "lib.h"
#include <stdint.h>


int main(int argc,char *argv[])
{
  if (argc > 2) {
    printf("Just add one file");
    return 1;  
  }

  const char *filename = argv[1];
  int width,height,channels;
  
  unsigned char *data = stbi_load(filename,&width,&height,&channels,4);
  
  pixel_colors(width, height, channels, data);
  
  stbi_image_free(data);
  return 0;
}
