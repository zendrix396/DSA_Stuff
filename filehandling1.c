#include <stdio.h>
#include <stdlib.h>
#define max 1000
int main(){
    FILE *file1,*file2,*target;
    char line[max]; //empty container for having content of the text files
    int ch1,ch2;
    file1 = fopen("file1.txt","r");
    file2= fopen("file2.txt","r");
    target = fopen("target.txt","w");
    while (1){
        ch1 =fgetc(file1);
        ch2= fgetc(file2);
        if (ch1==EOF&& ch2==EOF){
            break;
        }
        if (ch1!=EOF){
            fputc(ch1,target);
        }
        if (ch2!=EOF){
            fputc(ch1,target);
        }
        // if (fgets(line,max,file1)!=NULL){
        //     fputs(line,target);
        // }
        // if (fgets(line,max,file2)!=NULL){
        //     fputs(line,target);
        // }
        // if (fgets(line,max,file1)==NULL&&fgets(line,max,file2)==NULL){
        //     break;
        // }
    }
    fclose(file1);
    fclose(file2);
    fclose(target);

    return 0;
}