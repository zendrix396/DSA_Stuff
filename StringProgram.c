#include <stdio.h>
#include <string.h>

void xstrrev(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    // Using character arrays instead of string literals
    char str1[] = "To err is human...";
    char str2[] = "But to really mess things up...";
    char str3[] = "One needs to know C!!";
    
    // Array of pointers pointing to these character arrays
    char *s[] = {str1, str2, str3};
    int num_strings = sizeof(s) / sizeof(s[0]);
    
    // Print original strings
    printf("Original strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", s[i]);
    }
    
    // Reverse each string
    for (int i = 0; i < num_strings; i++) {
        xstrrev(s[i]);
    }
    
    // Print reversed strings
    printf("\nReversed strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", s[i]);
    }
    
    return 0;
}