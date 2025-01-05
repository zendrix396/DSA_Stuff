#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;
    int line_number = 1;
    file = fopen("file1.txt", "r");
    printf("%2d > ", line_number);
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
        if (ch == '\n') {
            line_number++;
            printf("%2d > ", line_number);
        }
    }
    fclose(file);
    return 0;
}