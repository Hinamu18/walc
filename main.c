#define STB_IMAGE_IMPLEMENTATION
#include "lib.h"
#include <stdint.h>


int main(int argc,char *argv[])
{
  const char *filename = argv[1];
  int width,height,channels;
  unsigned char *data = stbi_load(filename,&width,&height,&channels,0);
  
  if (data== NULL) {
      printf("Error: %s\n", stbi_failure_reason());
      return 1;
  }
  pixel_colors(width, height, channels,data);

  /*  
  if (argv[1][strlen(argv[1])-4] != '.'){
    printf("WORNG ^_^ TRY AGAIN ^.^");

    return 0;
  }
*/

  stbi_image_free(data);
  //fclose(img); 
  return 0;
}
