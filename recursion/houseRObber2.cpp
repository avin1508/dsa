#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int s, int e) {
        if (s > e) {
            return 0;
        }
        int inc = nums[s] + solve(nums, s + 2, e);
        int exe = solve(nums, s + 1, e);
        return max(inc, exe);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int op1 = solve(nums, 1, n - 1);
        int op2 = solve(nums, 0, n - 2);
        return max(op1, op2);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 2};  
    cout << "Maximum money that can be robbed: " << solution.rob(nums) << endl;
    return 0;
}
