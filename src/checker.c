#include <stdio.h>
#include <string.h>
#define ROW 4
#define COL 4
#define MOV 256

// Variables
int puzzle[ROW][COL];
char moves[MOV];

// Prototypes
void moveUp(int p[ROW][COL]);
void readFile(char* argv[]);
void readMoves(char* argv[]);
void printPuzzle(int p[ROW][COL]);
void printMoves(char m[MOV]);
void checkInput(int c, char* v[]);
int main(int argc, char* argv[]);

// Functions
void moveUp(int p[ROW][COL]) {
	int temp;
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(p[i][j] == 16) {
				p[i-1][j] = temp;
				p[i-1][j] = 16;
				p[i][j] = temp;		
			} else {
				printf("Illegal move");
			}
		}
	}
	// Copy to puzzle array
	memcpy(puzzle, p, (ROW*COL));
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
int main(int argc, char* argv[]) {
	printf("\n");
	checkInput(argc, argv);
	printf("\n");
	readFile(argv);
	printf("\n");
	readMoves(argv);
	//printPuzzle(puzzle);
	return 0;
}