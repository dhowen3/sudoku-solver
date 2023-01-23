#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int board[9][9];

void readFromCsv (char *csvInput[]) { 
    int counter = 0;
    for (int i = 0; i < 9; ++i) {
	for (int j = 0; j < 9;  ++j) {
	    board[i][j] = 5; 
	    counter += 1;
	}
    }
}








int main(int arc, char *argv[]) {
    readFromCsv(*argv);
    return 0;
}
