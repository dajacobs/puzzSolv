#include <stdio.h>

// Variables
int puzzle[4][4];

// Prototypes
void readFile(char* argv[]);
void readMove(char* argv[]);
void checkInput(int c, char* v[]);
int main(int argc, char* argv[]);

// Read file function
void readFile(char* argv[]) {
	printf("Input File: %s\n", argv[1]);
}
// Read moves function
void readMove(char* argv[]) {
	printf("Moves File: %s\n", argv[2]);
}
// Input Checker
void checkInput(int c, char* v[]) {
	int count;
	printf("Function: %s\n", v[0]);
	if(c > 1) {
		for(count = 1; count < c; count++) {
			printf("Argument: [%d] = %s\n", count, v[count]);
		}
	} else {
		printf("No more arguments.\n");
	}
}
// Main function
int main(int argc, char* argv[]) {
	checkInput(argc, argv);
	readFile(argv);
	readMove(argv);
	return 0;
}