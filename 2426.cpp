/*
In this problem we have to find 0<=i<j<=n-1
and such i and j pairs where num1[i]-num1[j]<=num2[i]-num2[j]+diff

we can re-arrange the condition as
num1[i]-num2[i]<=num1[j]-num2[j]+diff

so first we simply have to create a difference vector

vector<int> difference;
for (int i=0;i<nums1.size();i++){
        difference.push_back(num1[i]-num2[i]);
}

and now we just have to find num1[i]-num2[i]<=num1[j]-num2[j]+diff

then we do merge sort (recursive) and also creae a count function incrementor




*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long int count;
   
    void checkCount(vector<int>& nums, int start, int mid, int end, int d) {
        int l = start, r = mid + 1;
        while(l <= mid && r <= end) {
            if(nums[l] <= (nums[r]+d)) {
                count += (end - r + 1);
                l++;
            }
            else {
                r++;
            }
        }
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
    }
    
    void mergeSort(vector<int>& nums, int start, int end, int d) {
        if(start == end) 
            return;
        
        int mid = (start + end)/2;
        mergeSort(nums, start, mid, d);
        mergeSort(nums, mid+1, end, d);
        
        checkCount(nums, start, mid, end, d);
        return;
    }
    
    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) {
        count = 0;
        int n = a.size();
        vector<int>c(n);  
        
        for(int i=0; i<n; i++)
            c[i] = a[i]-b[i];               
			
        mergeSort(c, 0, n-1, d);
		
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, -1};
    vector<int> nums2 = {-2, 2}; 
    int diff = -1;
    
    cout << sol.numberOfPairs(nums1, nums2, diff);
    return 0;
}