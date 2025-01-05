#include <stdio.h>
#define max_line 1000
#define max_content 100
int main(){
    char line[max_line];
    FILE *file1,*file2;
    file1 = fopen("main1.txt","r");
    file2 = fopen("main2.txt","a");
    while (1){
        fputs(" ",file2);
        if (fgets(line,max_content,file1)!=NULL){
            fputs(line,file2);
        } else{
            break;
        }
    }
    fclose(file1);
    fclose(file2);
    return 0;
}