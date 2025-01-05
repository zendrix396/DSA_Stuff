#include <stdio.h>

int main(){
    FILE *file;
    long size;
    file  = fopen("students.txt","r");
    fseek(file,0,SEEK_END);
    size = ftell(file);
    fclose(file);
    printf("File Size: %ld bytes",size);
    return 0;
}