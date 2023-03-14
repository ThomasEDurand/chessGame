#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct cord{
  int x; // 0-7
  int y; // 0-7
} cord;


void swap(int** b, int x1, int y1, int x2, int y2);
void printBoard(int** b);
void getMove(int** b, int t);
int isValid(int** b, int x1, int y1, int x2, int y2);
int** newBoard();

int main(){
  int** board = newBoard();

  while(1 == 1){

    printBoard(board);
    getMove(board, 0);
    printBoard(board);
    getMove(board, 1);
    return 1;

  }

  return 0;
}


int** newBoard(){
  int temp[8][8] = {{4,2,3,5,6,3,2,4},
	      {1,1,1,1,1,1,1,1},
	      {7,0,7,0,7,0,7,0},
	      {0,7,0,7,0,7,0,7},
	      {7,0,7,0,7,0,7,0},
	      {0,7,0,7,0,7,0,7},
	      {8,8,8,8,8,8,8,8},
	      {11,9,10,12,13,10,9,11}};
  
  int** b = malloc(sizeof(int[8][8]));
  for(int i=0; i<8; i++){
    b[i] = malloc(sizeof(int[8]));
    for(int j =0; j<8; j++){
      b[i][j] = temp[i][j];
    }
  }
  return b;
}

// empty 0,
// use mod 6 to check type
// white: pawn 1, knight 2, bishop 3, rook 4, queen 5, king 6
// black: pawn 8, knight 9, bishop, 10, rook 11, queen 12, king 13

void printBoard(int** b){
  char c[14] = {'_', 'p', 'n', 'b', 'r', 'q', 'k', '#', 'P', 'N', 'B', 'R', 'Q', 'K'};
  printf("===========\n");
  for(int i=7; i>=0;i--){
    printf("%d|", i+1);
    for(int j=0; j<8;j++){
      printf("%c", c[b[i][j]]);
    }
    printf("|\n");
  }
  printf("===========\n");
  printf("|=ABCDEFGH|\n");
}

void getMove(int** b, int t){
  char line[1024];
  printf("MOVE:");
  fgets(line, 1024, stdin);
  int y1 = (int)(line[0])-97;
  int x1 = (int)(line[1])-49;
  printf("DEST:", x1, y1);
  fgets(line, 1024, stdin);
  int y2 = (int)(line[0])-97;
  int x2 = (int)(line[1])-49;
  if(isValid(b, x1, y1, x2, y2)==1){
    swap(b, x1, y1, x2, y2);
    return;
  }


}

// LOGIC FOR CHECKING IF MOVE IS LEAGL
int isValid(int** b, int x1, int y1, int x2, int y2){
  int p = b[x1][y1];
  
  if(p % 7 == 1){ // PAWN
    printf("PAWN\n");
    return 1;
  } else if (p % 7 == 2){ // KNIGHT

  } else if (p % 7 == 3){ // BISHOP
    
  } else if (p % 7 == 4){ // ROOK

  } else if (p % 7 == 5){ // QUEEN

  } else if (p % 7 == 6){ // KING

  } else { // NULL

  }
  return 0;
}

void swap(int** b, int x1, int y1, int x2, int y2){
  
  int t;
  printf("%d %d\n", x1, y1);
  if((x1 % 2 == 0 && y1 % 2 == 0) || (x1 % 2 == 1 && y1 % 2 == 1)){
    t = 7;
  } else {
    t = 0;
  } 
  
  b[x2][y2] = b[x1][y1];
  b[x1][y1] = t;

  
}

