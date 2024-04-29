#include <stdio.h>
#include "frequency.h"
#include "haffmanTree.h"

char *word = "aabacdab";

int main(){
  initFrequency(word);
  initTree();

  return 0;
}
