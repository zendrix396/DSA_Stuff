#include <stdio.h>
#include <stdlib.h>

// xgets with buffer overflow protection
char* xgets(char* str, int size) {
    int ch;
    int i = 0;
    
    // Leave space for null terminator
    size--;
    
    // Read characters until newline, EOF, or buffer full
    while (i < size && (ch = getchar()) != EOF && ch != '\n') {
        str[i++] = ch;
    }
    
    // If no characters read and EOF encountered
    if (i == 0 && ch == EOF) {
        return NULL;
    }
    
    // Add null terminator
    str[i] = '\0';
    
    // Clear any remaining input if buffer was full
    if (ch != EOF && ch != '\n') {
        while ((ch = getchar()) != EOF && ch != '\n')
            ;  // Discard excess characters
    }
    
    return str;
}

// xputs with error checking
int xputs(const char* str) {
    if (str == NULL) {
        return EOF;
    }
    
    while (*str != '\0') {
        if (putchar(*str) == EOF) {
            return EOF;
        }
        str++;
    }
    
    return (putchar('\n') == EOF) ? EOF : 1;
}

// Example usage with error handling
int main() {
    char line[10];  // Small buffer to test overflow protection
    
    printf("Enter a string (max 9 chars): ");
    
    if (xgets(line, sizeof(line)) != NULL) {
        printf("You entered: ");
        if (xputs(line) == EOF) {
            printf("Error writing output\n");
            return 1;
        }
    } else {
        printf("Error or EOF encountered while reading\n");
        return 1;
    }
    
    return 0;
}