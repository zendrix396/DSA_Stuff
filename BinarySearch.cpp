#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int n, vector<int> list){
    int low = 0;
    int high = list.size()-1;
    while (low<=high){
        int mid = (low+high)/2;
        if (list[mid]==n){
            return mid;
        } else if (list[mid]<n){
            low = mid+1;
        } else{
            high =  mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> vec;
    int len,n;cl
    cin>>len;
    for (int i=0;i<len;i++){
        int k;
        cin>>k;
        vec.push_back(k);
    }
    cout<< "Which Element to find?\n";
    cin>>n;
    cout<< binarySearch(n,vec);


    return -1;
}