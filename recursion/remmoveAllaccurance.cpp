#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to remove all occurrences of `part` from `s`
    void removeOccurrence(string &s, const string &part) {
        // Find the first occurrence of `part` in `s`
        int found = s.find(part);
        
        // If found, proceed with removing it
        if (found != string::npos) {
            // Get the substring before the found occurrence and after it
            string leftPart = s.substr(0, found);
            string rightPart = s.substr(found + part.size(), s.size());
            
            // Update the original string by concatenating left and right parts
            s = leftPart + rightPart;
            
            // Recursively call the function to check for further occurrences
            removeOccurrence(s, part);
        } else {
            return; // Base case: If `part` not found, return
        }
    }

    // Main function to remove all occurrences of `part` from `s`
    string removeOccurrences(string s, string part) {
        // Call the helper function
        removeOccurrence(s, part);
        return s; // Return the modified string
    }
};

int main() {
    Solution sol;
    
    // Test case
    string s = "daabcbaabcbc";
    string part = "abc";
    
    // Function call
    string result = sol.removeOccurrences(s, part);
    
    // Output the result
    cout << "Result after removing all occurrences: " << result << endl;
    
    return 0;
}
