#include <stdio.h>
#define ROW 4
#define COL 4
#define MOV 256

// Variables
int puzzle[ROW][COL];
char moves[MOV];

// Prototypes
void readFile(char* argv[]);
void readMove(char* argv[]);
void printPuzzle(int p[ROW][COL]);
void printMoves(char m[MOV]);
void checkInput(int c, char* v[]);
int main(int argc, char* argv[]);

// Read file function
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
// Read moves function
void readMove(char* argv[]) {
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
// Print puzzle function
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
// Print moves function
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
// Check input function
void checkInput(int c, char* v[]) {
	int count;
	printf("Function: %s\n", v[0]);
	if(c > 1) {
		for(count = 1; count < c; count++) {
			printf("Arguments: [%d] = %s\n", count, v[count]);
		}
	} else {
		printf("No more arguments.\n");
	}
}
// Main function
int main(int argc, char* argv[]) {
	printf("\n");
	checkInput(argc, argv);
	printf("\n");
	readFile(argv);
	printf("\n");
	readMove(argv);
	//printPuzzle(puzzle);
	return 0;
}