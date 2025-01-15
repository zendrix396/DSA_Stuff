#include <stdio.h>
#include <string.h>

// Define a sample structure
struct Student {
    int id;
    char name[50];
    float grade;
};

int main() {
    FILE *fp;
    
    // 1. Writing simple array
    int numbers[] = {1, 2, 3, 4, 5};
    fp = fopen("binary_numbers.bin", "wb");  // Note: 'b' for binary mode
    
    fwrite(numbers,                // pointer to data
           sizeof(int),           // size of each element
           5,                     // number of elements
           fp);                   // file pointer
    
    fclose(fp);

    // 2. Writing structure
    struct Student student = {
        .id = 123,
        .name = "John Doe",
        .grade = 85.5
    };
    
    fp = fopen("student.bin", "wb");
    
    fwrite(&student,              // pointer to structure
           sizeof(struct Student), // size of structure
           1,                     // number of structures
           fp);                   // file pointer
    
    fclose(fp);

    // 3. Reading and displaying the data back
    // Reading numbers
    int read_numbers[5];
    fp = fopen("binary_numbers.bin", "rb");
    
    fread(read_numbers,          // pointer to array
          sizeof(int),           // size of each element
          5,                     // number of elements
          fp);                   // file pointer
    
    printf("Numbers read from file:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", read_numbers[i]);
    }
    printf("\n\n");
    
    fclose(fp);

    // Reading student
    struct Student read_student;
    fp = fopen("student.bin", "rb");
    
    fread(&read_student,         // pointer to structure
          sizeof(struct Student), // size of structure
          1,                     // number of structures
          fp);                   // file pointer
    
    printf("Student read from file:\n");
    printf("ID: %d\n", read_student.id);
    printf("Name: %s\n", read_student.name);
    printf("Grade: %.1f\n", read_student.grade);
    
    fclose(fp);

    return 0;
}