#include <iostream>
#include <vector> // Include vector header
using namespace std;

void printSubarrayUtil(vector<int>& nums, int start, int end) {
    // Base case: if end reaches the size of nums, return
    if (end == nums.size()) {
        return;
    }
    
    // Print the current subarray
    for (int i = start; i < end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    // Recursive call to extend the end of the subarray
    printSubarrayUtil(nums, start, end + 1);
}

void printSubarray(vector<int>& nums) {
    // Loop through all possible starting points of the subarray
    for (int start = 0; start < nums.size(); start++) {
        int end = start + 1; // Start end from the next index
        printSubarrayUtil(nums, start, end);
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5}; // Initialize the vector with values
    printSubarray(nums); // Call the function to print subarrays
    return 0;
}
