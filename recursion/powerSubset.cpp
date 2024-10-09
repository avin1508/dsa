#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   
    void solve(vector<int>& nums, int index, vector<int> output, vector<vector<int>>& ans) {
  
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        solve(nums, index + 1, output, ans);
    
        output.push_back(nums[index]);
        solve(nums, index + 1, output, ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;  
        vector<int> output;       
        int index = 0;            
        solve(nums, index, output, ans);  
        return ans;              
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; 

 
    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets: " << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
