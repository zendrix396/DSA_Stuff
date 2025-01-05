#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 1000

int main() {
    FILE *file1, *file2, *target;
    char line[MAX_LINE];
    
    // Open first input file
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Error opening file1.txt\n");
        return 1;
    }
    
    // Open second input file
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Error opening file2.txt\n");
        fclose(file1);
        return 1;
    }
    
    // Open target file for writing
    target = fopen("merged.txt", "w");
    if (target == NULL) {
        printf("Error opening merged.txt\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }
    
    // Read and merge lines alternately
    while (1) {
        // Read and write line from first file
        if (fgets(line, MAX_LINE, file1) != NULL) {
            fputs(line, target);
        }
        
        // Read and write line from second file
        if (fgets(line, MAX_LINE, file2) != NULL) {
            fputs(line, target);
        }
        
        // Check if both files have reached EOF
        if (feof(file1) && feof(file2)) {
            break;
        }
    }
    
    // Close all files
    fclose(file1);
    fclose(file2);
    fclose(target);
    
    printf("Files merged successfully!\n");
    return 0;
}