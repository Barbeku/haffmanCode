char* encode(char *text, int size){
  char *encodeString = malloc(size*10);
  sprintf(encodeString, "\0");

  for(int i = 0; i < size; i++)
    sprintf(encodeString, "%s%s", encodeString, codes[text[i]]);

  return encodeString;
}
