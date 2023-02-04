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


char * readFromCsv (char * csvInput) { 
    //TODO board array defined here
}


bool checkCsvForValidBoard(char * csvInput) {
    FILE *filePointer;
    int maxLines = 9;
    int maxLineLength = 19; // 9 commas + 9 digits + return
    int currentCharValue, currentLineNum = 0, currentLinePosition = 0, currentCommaOnLine = 0;
    filePointer = fopen(csvInput, "r");
    char invalidErrorMessage[] = "invalid csv detected. terminating without result\n";
    while(true) {
	currentCharValue = fgetc(filePointer);
	if (feof(filePointer)) break; // end of file character reached
	else ++currentLinePosition;

	if (currentLinePosition >= 19 || currentLineNum >= 9) {
	    fclose(filePointer);
	    printf(invalidErrorMessage); 
	    return false;
	}

	if (currentCharValue == '\n') {
	    currentLinePosition = 0;
	    if (currentCommaOnLine != 8) {
		printf(invalidErrorMessage); 
		fclose(filePointer);
		return false;
	    }
	    currentCommaOnLine = 0;
	    ++currentLineNum;
	} else if (currentCharValue == ',') {
	    ++currentCommaOnLine;
	} else if ('1' <= currentCharValue && currentCharValue <= '9') {
	    //do nothing
	} else {
	    printf(invalidErrorMessage);
	    fclose(filePointer);
	    return false;
	}
    }
    fclose(filePointer);
    return true;
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
	int argumentLength = strlen(argv[1]);
	int numPeriods = 0;
	for (int i = 0; i < argumentLength; ++i) {
	    if (argv[1][i] == '.') {
		++numPeriods;
	    }
	}
	if (numPeriods != 1) {
	    printf("unexpected filetype passed to the program. ");
	    printf("terminating without result\n");
	    return false;
	}

	char fileNameClone[argumentLength];
	strcpy(fileNameClone, argv[1]);
	char *splitByPeriod = strtok(fileNameClone, ".");
	splitByPeriod = strtok(NULL, "."); // run a second time to get post-period token

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
    else csvFileName = argv[1];
    //puts(csvFileName); debugging, delete

    bool validBoard = checkCsvForValidBoard(csvFileName);
    //if (!validBoard) return -1;

    //readFromCsv(csvFileName);

    printf("args ok\n");
    return 0;
}
