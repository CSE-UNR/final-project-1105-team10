//Jordan Cadelina
//Final Project

#include <stdio.h>
#include <stdbool.h>

// Function to read the decoded story from a file
void readDecodedStory(const char *filename, char *buffer, int bufferSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    int i = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && i < bufferSize - 1) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0'; // Null-terminate the string

    fclose(file);
}

// Function to display the story to the console
void displayStory(const char *story) {
    printf("Here's your completed story:\n\n");
    printf("%s\n", story);
}

