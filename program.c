#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int* arr = (int*) malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    int largest= *arr;
    for (int i=1;i<n;i++){
        if (*(arr+i)>largest){
            largest = *(arr+i);
        }
    }
    printf("%d\n",largest);

    return 0;
}