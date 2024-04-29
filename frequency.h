#include <stdio.h>

#define ASCII_SIZE 255

int frequency[ASCII_SIZE];

void calcFrequency(char*);
void showFrequency();

void initFrequency(char *word){
  for(int i = 0; i < ASCII_SIZE; i++)
    frequency[i] = 0;

  calcFrequency(word);
}

void calcFrequency(char *word){
  for(; *word != '\0'; word++)
    frequency[*word]++;
}

void showFrequency(){
  for(int i = 0; i < ASCII_SIZE; i++)
    if(frequency[i] != 0)
      printf("%c: %d\n", i, frequency[i]);
}
