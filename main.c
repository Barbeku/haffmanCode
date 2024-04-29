#include <stdio.h>
#include <string.h>
#include "frequency.h"
#include "haffmanTree.h"
#include "decodeEncode.h"

char *text = "aabacdab";

int main(){
  initFrequency(text);
  initTree();


//  showFrequency();
//  showCodes();
//  showNodes();

  char *encodeString = encode(text, strlen(text));
  printf("%s\n", encodeString);

  char *decodeString = decode(encodeString, strlen(encodeString));
  printf("%s\n", decodeString);

  printf("start size: %d bits, encode size: %d bits", strlen(text)*8, strlen(encodeString));

  return 0;
}
