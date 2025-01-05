#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    FILE *source,*target;
    char string[1000];
    char ch;
    source = fopen("source.txt","r");
    target = fopen("target.txt","w");
    // while ((ch = fgetc(source)) != EOF) {
    //     if (ch>='a' && ch<='z'){
    //         ch = ch-32;
    //     }
    //     fputc(ch,target);
    // }
    while (fgets(string,1000,source)!=NULL){
        for (int i=0;string[i]!='\0';i++){
            string[i] = toupper(string[i]);
        }
        fputs(string,target);
    }
    fclose(source);
    fclose(target);
    
    return 0;
}