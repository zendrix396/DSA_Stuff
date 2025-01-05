#include <stdio.h>
#define N 5
int main(){
    int arr[N] = {1,2,3,4,5};
    int *p = arr;
    for (int i=0;i<N;i++){
        printf("%d ",*(p+i));
    }
    
    return 0;
}