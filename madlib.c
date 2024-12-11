#include <stdio.h>
#include <stdbool.h>

#define FILE_NAME "madlib2.txt"
#define ROWS 50
#define COLUMNS 150

void userInputStorage(char madlib[][COLUMNS], char input[], int *readLines);
void getUserInput(char input[]);
void replacePlaceHolder(char madlib[][COLUMNS], char input[], int lineIndex);
void displayStory(char madlib[][COLUMNS], int readLines);
void addNewline(char madlib[][COLUMNS], int lineIndex, int j);

FILE *file;

int main() {
	char madlib[ROWS][COLUMNS]; 
	char input[50];            
	int readLines = 0;         

   
	file = fopen(FILE_NAME, "r");
	if (file == NULL) {
		printf("Error: File '%s' not found. Please ensure it exists.\n", FILE_NAME);
        return 0;
    }


	userInputStorage(madlib, input, &readLines);

 
	displayStory(madlib, readLines);

return 0;
}

void userInputStorage(char madlib[][COLUMNS], char input[], int *readLines) {
    *readLines = 0; 

    while (fgets(madlib[*readLines], COLUMNS, file) != NULL && *readLines < ROWS) {
        (*readLines)++;
    }
    fclose(file); 

  
    for (int i = 0; i < *readLines; i++) {
        if (madlib[i][0] == 'A' || madlib[i][0] == 'V' || madlib[i][0] == 'N') {
            if (madlib[i][1] == '\n' || madlib[i][1] == '\0') {
                if (madlib[i][0] == 'A') printf("Please enter an adjective: ");
                if (madlib[i][0] == 'V') printf("Please enter a verb: ");
                if (madlib[i][0] == 'N') printf("Please enter a noun: ");

                getUserInput(input);
                replacePlaceHolder(madlib, input, i);           }
        }
    }
}

void getUserInput(char input[]){
	scanf("%s", input);
}

void replacePlaceHolder(char madlib[][COLUMNS], char input[], int lineIndex){
	int j = 0;
	while (input[j] != '\0' && j < COLUMNS - 2) {
		madlib[lineIndex][j] = input[j];
		j++;
	}
	
	addNewline(madlib, lineIndex, j);
}

void addNewline(char madlib[][COLUMNS], int lineIndex, int j) {
	madlib[lineIndex][j] = '\n';   
	madlib[lineIndex][j + 1] = '\0';
}


void displayStory(char madlib[][COLUMNS], int readLines) {
    printf("\nUpdated Story:\n");
    for (int i = 0; i < readLines; i++) {
        printf("%s", madlib[i]);
    }
}

