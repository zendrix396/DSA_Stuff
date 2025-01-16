#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newList;
        for (int i : nums1) {
            newList.push_back(i);
        }
        for (int j : nums2) {
            newList.push_back(j);
        }
        sort(newList.begin(), newList.end());
        int n = newList.size();
        double median = 0.0;
        if (n % 2 == 0) {
            median = (newList[n / 2 - 1] + newList[n / 2]) / 2.0;
        } else if (n == 0) {
            return 0.0;
        } else if (n == 1) {
            return newList[0];
        } else {
            median = newList[n / 2];
        }
        return median;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;
    return 0;
}