#include <stdio.h>

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    int c;
    int chars = 0;
    int lines = 0;
    int words = 0;
    int in_word = 0;

    while ((c = fgetc(file)) != EOF) {
        chars++;

        if (c == '\n')
            lines++;

        if (c == ' ' || c == '\n' || c == '\t')
            in_word = 0;
        else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    printf("lines: %d\n", lines);
    printf("words: %d\n", words);
    printf("chars: %d\n", chars);

    fclose(file);
    return 0;
}