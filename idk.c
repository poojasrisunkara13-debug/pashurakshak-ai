#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    int ch, characters = 0, words = 0, lines = 0;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') lines++;
        if (isspace(ch)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) words++;  // Count last word if no space after it
    fclose(file);
    printf("Characters: %d\nWords: %d\nLines: %d\n", characters, words, lines);
    return 0;
