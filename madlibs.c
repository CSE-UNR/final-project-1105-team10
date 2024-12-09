//Jordan Cadelina
//Final Project

#include <stdio.h>
#include <stdbool.h>

// Read Decode 
void readDecodedStory(const char *filename, char *buffer, int bufferSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s", filename);
        return;
    }

    int i = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && i < bufferSize - 1) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0'; 

    fclose(file);
}

// Display story
void displayStory(const char *story) {
    printf("Complete:\n\n");
    printf("%s\n", story);
}

