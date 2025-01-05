#include <stdio.h>

int main(){
    for (int j=7;j>0;j--){
    for (int i=65;i<65+j;i++){
        printf("%c ",i);
    }
    for(int k=0;k<(4*(-(j-7)))-2;k++){
        printf(" ");
    }
    for (int i=65+j-1;i>64;i--){
        if (i!=71){
            printf("%c ",i);
        }
    }
    printf("\n");
    }
    return 0;
}