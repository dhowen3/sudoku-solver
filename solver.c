#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


char* csvFileName;
int board[9][9];
bool boardDefinedValues[9][9];

struct undefinedCell {
    bool possibleValues[9]; // index 0 represents 1 being possible, index 8 represents 9 being possible
};


void readFromCsv (char csvInput[]) { 
}

// TODO write tomorrow
bool checkCsvForValidBoard() {
    // TODO read from file to char[][]. split by \n
    // TODO check that there are 9 commas on each line
	// TODO also check in the same for-loop each character in CSV is either {[comma], [digit], or [\n]}
    return false;
}

// runs a few checks to make sure filename passed in command-line arguments will not cause problems
bool checkProgramInput(int argc, char *argv[]) {
    // check that the executable and the csv are passed as arguments, nothing more and nothing less
    {
	if (argc != 2) {
	    printf("unexpected number of arguments passed to program. ");
	    printf("terminating without result\n");
	    return false;
	}
    }
    // check that the file passed to the program has a .csv extension
    {
	int numPeriods = 0;
	printf("ok"); //

	for (int i = 0; i < strlen(argv[1]); i++) {
	    int currentChar = argv[1][i];
	    if (currentChar == '.') {
		++numPeriods;
	    }
	}
	printf("%d", numPeriods); //
	if (numPeriods != 1) {
	    printf("unexpected filetype passed to the program. ");
	    printf("terminating without result\n");
	    return false;
	}
	char * fileNameClone;
	strcpy(argv[1],fileNameClone);
	char *splitByPeriod = strtok(fileNameClone, ".");
	splitByPeriod = strtok(NULL, "."); 
	printf("%s", splitByPeriod); //

	int comparison = strcmp(splitByPeriod, "csv");
	if (comparison != 0) {
	    printf("unexpected filetype passed to the program. ");
	    printf("terminating without result\n");
	    return false;
	}
    }
    return true;
}

int main(int argc, char *argv[]) {
    bool argsOk = checkProgramInput(argc, argv);
    if (!argsOk) return -1;
    printf("args ok\n");
    return 0;
}
