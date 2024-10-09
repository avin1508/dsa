#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    // Recursive helper function to find max profit
    void buyAndSellStock(vector<int>& prices, int i, int &minPrice, int &maxProfit) {
        // Base case: if we reach the end of the array, return
        if (i == prices.size()) {
            return;
        }

        // Update the minimum price if the current price is lower
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate today's profit
        int todayProfit = prices[i] - minPrice;

        // Update max profit if today's profit is higher
        if (todayProfit > maxProfit) {
            maxProfit = todayProfit;
        }

        // Recursive call to process the next day
        buyAndSellStock(prices, i + 1, minPrice, maxProfit);
    }

    // Main function to find the maximum profit
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Initialize to a very large value
        int maxProfit = 0;       // Initialize max profit to 0
        buyAndSellStock(prices, 0, minPrice, maxProfit);  // Start recursion from day 0
        return maxProfit;        // Return the calculated max profit
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Calculate the max profit
    int result = sol.maxProfit(prices);

    // Output the result
    cout << "Maximum profit: " << result << endl; // Expected Output: 5

    return 0;
}
