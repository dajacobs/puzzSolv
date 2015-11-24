#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROW 4
#define COL 4
#define MOV 256

// Variables
int puzzle[ROW][COL];
char moves[MOV];
int solved[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

// Prototypes
void moveUp(int p[ROW][COL]);
void moveDown(int p[ROW][COL]);
void moveLeft(int p[ROW][COL]);
void moveRight(int p[ROW][COL]);
void readFile(char* argv[]);
void readMoves(char* argv[]);
void applyMoves(void);
void printPuzzle(int p[ROW][COL]);
void printMoves(char m[MOV]);
void checkInput(int c, char* v[]);
int checkState(int p[ROW][COL], int q[ROW][COL], size_t s);
int compareState(int p[ROW][COL], int q[ROW][COL]);
int main(int argc, char* argv[]);

// Functions
void moveUp(int p[ROW][COL]) {
	int temp;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(i < 0) {
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i-1, j);
				printf("\n");
				break;		
			} else if(p[i][j] == 16 || i  > 0) {
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i-1, j);
				printf("\n");
				temp = p[i-1][j];
				p[i-1][j] = p[i][j];
				p[i][j] = temp;
				goto terminate;
			}
		}
	}
terminate:	
	// Copy to puzzle array
	memcpy(puzzle, p, 16);
}
void moveDown(int p[ROW][COL]) {
	int temp;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(i > 3) {	
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i+1, j);
				printf("\n");
				break;	
			} else if(p[i][j] == 16 || i < 4) {
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i+1, j);
				printf("\n");
				temp = p[i+1][j];
				p[i+1][j] = p[i][j];
				p[i][j] = temp;
				goto terminate;
			}
		}
	}
terminate:	
	// Copy to puzzle array
	memcpy(puzzle, p, 16);
}
void moveLeft(int p[ROW][COL]) {
	int temp;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(j < 0) {
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i, j-1);
				printf("\n");
				break;		
			} else if(p[i][j] == 16 || j > 0) {
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i, j-1);
				printf("\n");
				temp = p[i][j-1];
				p[i][j-1] = p[i][j];
				p[i][j] = temp;
				goto terminate;
			}
		}
	}
terminate:
	// Copy to puzzle array
	memcpy(puzzle, p, 16);
}
void moveRight(int p[ROW][COL]) {
	int temp;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(j > 3) {
				printf("j > 3");
				printf("\n");
				printf("%d %d\n", i, j);
				printf("%d %d\n", i, j+1);
				printf("\n");
			 	goto terminate;
			} else if(p[i][j] == 16){
				if((j+1) > 3) {
					break;
				} else {
					printf("j < 4");
					printf("\n");
					printf("%d %d\n", i, j);
					printf("%d %d\n", i, j+1);
					printf("\n");
					temp = p[i][j+1];
					p[i][j+1] = p[i][j];
					p[i][j] = temp;
					goto terminate;
				}
			}
		}
	}
terminate:
	// Copy to puzzle array
	memcpy(puzzle, p, 16);
}
void readFile(char* argv[]) {
	// Variables
	char const* const fileName = argv[1];
	FILE* file;
	// Print intput file to user
	printf("Input File: %s\n", fileName);
	// Open file and store variables
	file = fopen(fileName, "r");
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			fscanf(file, "%d", &puzzle[i][j]);
		}
	}
	// Output to user
	printf("Puzzle stored:\n");
	printPuzzle(puzzle);
	// Close file
	fclose(file);
}
void readMoves(char* argv[]) {
	// Variables
	char const* const fileName = argv[2];
	FILE* file;
	// Print input file to user
	printf("Moves File: %s\n", fileName);
	// Open file and store variables
	file = fopen(fileName, "r");
	for(int i = 0; i < MOV; i++) {
		fscanf(file, "%c\n", &moves[i]);
	}
	// Output to user
	printf("Moves stored:\n");
	printMoves(moves);
	fclose(file);
}
void applyMoves(void) {
	printf("Applying moves:");
	for(int i = 0; i < MOV; i++) {
		// Move up
		if(moves[i] == 'w') {
			printf("Moved Up:\n");
			printPuzzle(puzzle);
			moveUp(puzzle);
		// Move down	
		} else if(moves[i] == 's') {
			printf("Moved down:\n");
			printPuzzle(puzzle);
			moveDown(puzzle);
		// Move left	
		} else if(moves[i] == 'a') {
			printf("Moved left:\n");
			printPuzzle(puzzle);
			moveLeft(puzzle);
		// Move right
		} else if(moves[i] == 'd') {
			printf("Moved right:\n");
			printPuzzle(puzzle);
			moveRight(puzzle);
		}
	}
}
void printPuzzle(int p[ROW][COL]) {
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			printf("Puzzle[%d][%d]= ", i, j);
			if(p[i][j] < 10) {
				printf(" ");
			}
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
void printMoves(char m[MOV]) {
	for(int i = 0; i < MOV; i++) {
		if(moves[i] != '\0') {
			printf("Moves[%d]= ", i);
			printf("%c", moves[i]);
		} else {
			break;
		}
		printf("\n");
	}
}
void checkInput(int c, char* v[]) {
	int count;
	printf("Function: %s\n", v[0]);
	if(c > 1) {
		for(count = 1; count < c; count++) {
			printf("Arguments: [%d] = %s\n", count, v[count]);
		}
	} else {
		printf("No input arguments\n");
	}
}
int checkState(int p[ROW][COL], int q[ROW][COL], size_t s) {
	int n;
	int result;
	n = memcmp(p, q, s);
	// Greater
	if(n > 0) {
		result = 1;
	// Lesser
	} else if(n < 0) {
		result = -1;
	// Equal	
	} else {
		result = 0;
	}
	return result;
}
int compareState(int p[ROW][COL], int q[ROW][COL]) {
	int i, j;
	int result = 1;
	for(i = 0; i < ROW; i++) {
		for(j = 0; j < COL; j++) {
			if(p[i][j] != q[i][j]) {
				result = 0;
				break;
			}
		}
	}
	return result; 
}
int main(int argc, char* argv[]) {
	printf("\n");
	checkInput(argc, argv);
	printf("\n");
	readFile(argv);
	printf("\n");
	readMoves(argv);
	printf("\n");
	moveRight(puzzle);
	// applyMoves();
	// printf("\n");
	// printPuzzle(puzzle);
	// printf("\n");
	printf("FINAL PRINT OUT\n");
	printPuzzle(puzzle);
	return 0;	
}