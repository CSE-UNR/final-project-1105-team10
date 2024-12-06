//Final project 
//Amanda's part

#include <stdio.h>
#define FILE_NAME "madlib1.txt"

void userInputStorage(int row, int column, char madlib[][column]);
void encodedStory();

int main() {
	int row = 21, column = 150;
	char madlib[row][column];
	printf("Enter an adjective: ");
	scanf("%s", madlib[2]);
	printf("Enter an adjective: ");
	scanf("%s", madlib[4]);
	printf("Enter a noun: ");
	scanf("%s", madlib[6]);
	printf("Enter a noun: ");
	scanf("%s", madlib[8]);
	printf("Enter a verb: ");
	scanf("%s", madlib[10]);
	printf("Enter a noun: ");
	scanf("%s", madlib[12]);
	printf("Enter a noun: ");
	scanf("%s", madlib[14]);
	printf("Enter a noun: ");
	scanf("%s", madlib[16]);
	printf("Enter a noun: ");
	scanf("%s", madlib[18]);
	printf("Enter a noun: ");
	scanf("%s", madlib[20]);

	userInputStorage(row, column, madlib);
	encodedStory();

return 0;
}

void userInputStorage(int row, int column, char madlib[][column]){
	FILE *fp;
	fp = fopen("madlib1.txt", "w");
	if (fp == NULL){
	printf("Can't open file for writing\n");
return;
}

   
	for (int i = 0; i < row; i++) {
		if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20){
			fprintf(fp, "%s\n", madlib[i]);
		}
	}

fclose(fp);
}

void encodedStory() {
	FILE *fp = fopen("madlib1.txt", "r");
	if (fp == NULL) {
		printf("Can't open file for reading.\n");
return;
	}

	char input[150];
	printf("User inputs:\n");
	while (fgets(input, sizeof(input), fp) != NULL){
		printf("%s", input);
	}
fclose(fp);
}

