#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return true;
        } else {
            for (size_t i = 0; i < nums.size(); ++i) {
                vector<int> newlist(nums.begin(), nums.end());
                newlist.erase(newlist.begin() + i);
                if (is_sorted(newlist.begin(), newlist.end())) {
                    return true;
                }
            }
            return false;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {4,2,1};
    cout << "Result for nums1: " << solution.checkPossibility(nums1) << endl;
    return 0;
}