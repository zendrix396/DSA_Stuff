#include <stdio.h>

void bubbleSort(int arr[],int size){
    for (int i=0;i<size;i++){
        for (int j=0;j<size-i-1;j++){
            if (arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

void linearSort(int arr[],int size){
    int max = arr[0];
    for (int i=1;i<size;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    int* count=  (int*) calloc(max+1,sizeof(int));
    int* output= (int*) malloc(size*sizeof(int));
    for (int i=0;i<size;i++){
        count[arr[i]]++;
    }
    for (int i=1;i<=max;i++){
        
    }

}

void printArr(int arr[],int size){
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[5] = {2,5,11,552,131};
    bubbleSort(arr,5);
    printArr(arr,5);
    return 0;
}