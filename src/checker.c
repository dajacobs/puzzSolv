#include <stdio.h>
#define ROW 4
#define COL 4

// Variables
int puzzle[ROW][COL];

// Prototypes
void readFile(char* argv[]);
void readMove(char* argv[]);
void printPuzzle(int p[ROW][COL]);
void checkInput(int c, char* v[]);
int main(int argc, char* argv[]);

// Read file function
void readFile(char* argv[]) {
	// Variables
	char const* const fileName = argv[1];
	FILE* file;
	// Open file and store variables
	printf("Input File: %s\n", fileName);
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
	printf("Moves File: %s\n", argv[2]);
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
	checkInput(argc, argv);
	readFile(argv);
	//readMove(argv);
	//printPuzzle(p);
	return 0;
}