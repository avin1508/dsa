#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3}; 
    int val = 3; 
    int newLength = solution.removeElement(nums, val);
    
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
