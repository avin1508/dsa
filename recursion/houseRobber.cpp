#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int solve(vector<int>& nums, int s, int e) {
        if (s > e) {
            return 0;
        }
        int include = nums[s] + solve(nums, s + 2, e);
        int exclude = solve(nums, s + 1, e);
        return max(include, exclude);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        return solve(nums, s, e);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum money that can be robbed: " << solution.rob(nums) << endl;
    return 0;
}
