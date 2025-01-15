#include <iostream>
#include <vector>  

using namespace std;

vector<int> bubblesort(vector<int>& list) {
    for (int i = 0; i < list.size(); i++) {
        for (int j = 0; j < list.size()-i-1; j++) {
            if (list[j] > list[j+1]) {
                int temp = list[j]; 
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    return list;
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5}; 
    int target = 8; 
    
    candidates = bubblesort(candidates);  
    vector<vector<int>> res;
    printf("%d",candidates);
    for (const int& num : candidates) {
        cout << num << " ";
    }
    cout << endl;
    // vector<int> vec1;
    // int sum = 0;
    // int count = 0;
    
    // for (int& num : candidates) {
    //     sum += num;
    //     vec1.push_back(num);
    //     if (sum == target) {
    //         res.push_back(vec1);
    //         vec1.clear();
    //         count++;
    //     }
    //     else if (sum > target) {
    //         sum = 0;
    //         break;
    //     }
    // }
    
    return 0;
}