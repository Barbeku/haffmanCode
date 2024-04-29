#define MAX_BUFER_SIZE 8*4 //int

char* encode(char *text, int size){
  char *encodeString = malloc(size*10);
  sprintf(encodeString, "\0");

  for(int i = 0; i < size; i++)
    sprintf(encodeString, "%s%s", encodeString, codes[text[i]]);

  return encodeString;
}

char* decode(char *encodeText, int size){
  char *decodeText = malloc(size);
  char buffer[MAX_BUFER_SIZE];
  sprintf(buffer, "\0");
  sprintf(decodeText, "\0");

  for(int j = 0; j < size; j++){
    sprintf(buffer, "%s%c", buffer, encodeText[j]);

    for(int i = 0; i < ASCII_SIZE; i++){
      if(frequency[i] == 0) continue;
      if(strcmp(buffer, codes[i]) == 0){
        sprintf(buffer, "");
        sprintf(decodeText, "%s%c", decodeText, i);
        break;
      }
    }
  }

  return decodeText;
}
