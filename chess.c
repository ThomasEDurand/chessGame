#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define CMDLEN 7

void printBoard(char board[8][8]) {
 for(int i=0;i<8;i++){
	printf("%d| ", 8-i);
 	for(int j=0;j<8;j++){;
        	printf("%c ", board[i][j]);
	}
	printf("\n");	
	}
 printf("   a b c d e f g h\n");
}


void move(char board[8][8], char buffer[CMDLEN]){
	// NOTATION
	// upperCase = White lowerCase = Black
	// * = Empty Square
	// eg Pc3f5: pawn c3 to f5, peiceStartDestination
	//
	printf("peice 1 %c\n", buffer[0]);
	printf("start row %c\n", buffer[1]);
	printf("start col %c\n", buffer[2]);
	printf("dest row %c\n", buffer[3]);
	printf("dest col %c\n", buffer[4]);
}
int main(){
 char board[8][8] = {{'r','n','b','q','k','b','k','r'},
	 	{'p','p','p','p','p','p','p','p'}, 
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'*','*','*','*','*','*','*','*'},
		{'P','P','P','P','P','P','P','P'},
		{'R','N','B','Q','K','B','N','P'}};

 int turn = 1;
 char buffer[CMDLEN];

 system("clear");
 printBoard(board);
 
 while(fgets(buffer, CMDLEN, stdin)){
	system("clear");
	printBoard(board);
        
	printf("Turn %d ", turn);
	(turn % 2 == 1) ? printf("White Move: \n") : printf("Black Move: \n");

	move(board, buffer);
	turn++;
 }
}

