#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(string digits, int index, string output, vector<string> &ans, vector<string> &map) {
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0'; 
        string value = map[digit];  

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, index + 1, output, ans, map);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string output = "";
        int index = 0;

        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, index, output, ans, map);
        return ans;  
    }
};
