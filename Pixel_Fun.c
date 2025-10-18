#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void pixel_colors(int width, int height, int channels, unsigned char *data) {
  int numPixels = width * height;
  int hexPerPixel = channels * 2 + 1; // 2 hex chars per byte, 1 for newline
  int bufferSize = hexPerPixel + 1;   // +1 for null 

  FILE *img = fopen("hex.txt", "wb");

  char hex[] = "0123456789ABCDEF";

  // malloc memory for each pixel's hex
  char **pixelData = malloc(numPixels * sizeof(char *));

  for (int i = 0; i < numPixels; i++) {
    pixelData[i] = malloc(bufferSize);

    int dataIndex = i * channels;
    int pos = 0;
    for (int k = 0; k < channels; k++) {
      unsigned char byte = data[dataIndex + k];
      pixelData[i][pos++] = hex[(byte >> 4) & 0xF];
      pixelData[i][pos++] = hex[byte & 0xF];
    }
    pixelData[i][pos++] = '\n';
    pixelData[i][pos] = '\0';
  }


  sorting(pixelData,numPixels);
  

  // Write to file
  for (int i = 0; i < numPixels; i++) {
    fputs(pixelData[i], img);
    free(pixelData[i]);
  }

  free(pixelData);
  fclose(img);
}

int compareStrings(const void *a, const void *b) {
    const char *strA = *(const char **)a;
    const char *strB = *(const char **)b;
    return strcmp(strA, strB);
}

void sorting(char **buffer,int numPixels){
    qsort(buffer, numPixels, sizeof(char *), compareStrings);
}
