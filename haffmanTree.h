#include <stdlib.h>

#define MAX_TREE_SIZE 100
#define NIL 0

enum { LEAF, NO_LEAF };

enum { LEFT, RIGHT };

char *codes[ASCII_SIZE];

typedef struct{
  char isLeaf;
  char symbol;
  int number;
  int left, right;
  int parent;
} NODE;

NODE tree[MAX_TREE_SIZE]; //НУЛЕВОЙ ЭЛЕМЕНТ ИСПОЛЬЗОВАТЬ НЕЛЬЗЯ!!!!!!!!!!!!!!!!!!!!!!!!!
int posTree = 1; 

int sumNumber = 0;

void addFrequencyToTree();
void organiseTree();
int* findTwoSmallest();
void showNodes();
void getCodesForSymbols(int, char, int, int);
char* showInBinary(char, int);


void initTree(){
  addFrequencyToTree();
  organiseTree();

  getCodesForSymbols(posTree-1, 0, -1, -1);

//  showNodes();
}

void addFrequencyToTree(){
  for(int i = 0; i < ASCII_SIZE; i++)
    if(frequency[i] != 0){
      sumNumber += frequency[i];
      tree[posTree].symbol = i;
      tree[posTree].number = frequency[i];
      tree[posTree++].isLeaf = LEAF;
    }
}

void organiseTree(){
  for(int i = 1; i < posTree; i++)
    if(tree[i].number == sumNumber){
      printf("end\n");
      return;
    }

  int *twoSmallest = findTwoSmallest();
//  showFrequency();
//  printf("%d, %d\n", twoSmallest[0], twoSmallest[1]);
  tree[twoSmallest[0]].parent = posTree;
  tree[twoSmallest[1]].parent = posTree;
  tree[posTree].number = tree[twoSmallest[0]].number + tree[twoSmallest[1]].number;
  tree[posTree].isLeaf = NO_LEAF;
  tree[posTree].left = twoSmallest[0];
  tree[posTree].right = twoSmallest[1];
  posTree++;

  organiseTree();
}

int* findTwoSmallest(){
  int smallest, almostSmallest;
  smallest = almostSmallest = -1;

  for(int i = 1; i < posTree; i++){
    if(tree[i].parent != NIL) continue;

    if(smallest == -1) smallest = i;
    else if(almostSmallest == -1 || tree[i].number < tree[almostSmallest].number){
      almostSmallest = i;
      if(tree[almostSmallest].number < tree[smallest].number){
        almostSmallest = smallest;
        smallest = i;
      }
    }
  }

  int *returnArr = malloc(4*2);
  returnArr[0] = smallest;
  returnArr[1] = almostSmallest;

  return returnArr;
}

void showNodes(){
  for(int i = 1; i < posTree; i++){
    if(tree[i].parent != NIL)
      printf("---------- ");

      printf("%2d - isLeaf: %7s, number: %3d, symbol: %c, parent: %2d, left: %2d, right: %2d", i, tree[i].isLeaf == LEAF ? "LEAF" : "NO_LEAF", tree[i].number, tree[i].isLeaf == LEAF ? tree[i].symbol : 'N', tree[i].parent, tree[i].left, tree[i].right);

    if(tree[i].parent != NIL)
      printf(" ----------");

    printf("\n");
  }
}

void getCodesForSymbols(int root, char path, int depth, int direction){
  if(direction != -1)
    path = path | (direction << depth);

  if(tree[root].isLeaf == LEAF){
    codes[tree[root].symbol] = showInBinary(path, depth);
    printf("%c: %s, %d\n", tree[root].symbol, showInBinary(path, depth), path);
    return;
  }
  depth++;

  getCodesForSymbols(tree[root].left, path, depth, LEFT);
  getCodesForSymbols(tree[root].right, path, depth, RIGHT);
}

char* showInBinary(char x, int depth){
  char *string = malloc(depth+2);
  string[depth+1] = '\0';

  for(int i = 0; i <= depth; i++)
    if(x & (1 << i))
      string[i] = '1';
    else
      string[i] = '0';

  return string;
}
