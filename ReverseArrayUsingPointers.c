#include <stdio.h>
#define row 3   
#define col 3
int main(){
    int *p;
    int a[row][col] = {{1,2,3},{4,5,6},{7,8,9}};  
    for (p=&a[0][0]; p<=&a[row-1][col-1]; p++){
        printf("%d ",*p);
        if ((p-&a[0][0]+1)%col==0){
            printf("\n");
        }
    }
    return 0;
}