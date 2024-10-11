#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    bool isSafe(int x, int y, int n, vector<vector<int>> &mat, vector<vector<int>> &visited) {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && mat[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }

    void solve(vector<vector<int>> &mat, int n, int srcX, int srcY, string path, vector<vector<int>> &visited, vector<string> &ans) {
        if (srcX == n - 1 && srcY == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[srcX][srcY] = 1;

        // Down
        int newX = srcX + 1;
        int newY = srcY;
        if (isSafe(newX, newY, n, mat, visited)) {
            path.push_back('D');
            solve(mat, n, newX, newY, path, visited, ans);
            path.pop_back();
        }

        // Left
        newX = srcX;
        newY = srcY - 1;
        if (isSafe(newX, newY, n, mat, visited)) {
            path.push_back('L');
            solve(mat, n, newX, newY, path, visited, ans);
            path.pop_back();
        }

        // Right
        newX = srcX;
        newY = srcY + 1;
        if (isSafe(newX, newY, n, mat, visited)) {
            path.push_back('R');
            solve(mat, n, newX, newY, path, visited, ans);
            path.pop_back();
        }

        // Up
        newX = srcX - 1;
        newY = srcY;
        if (isSafe(newX, newY, n, mat, visited)) {
            path.push_back('U');
            solve(mat, n, newX, newY, path, visited, ans);
            path.pop_back();
        }

        visited[srcX][srcY] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        if (mat[0][0] == 0) {
            return ans;
        }

        int n = mat.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        solve(mat, n, 0, 0, path, visited, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution sol;
    vector<string> result = sol.findPath(mat);

    for (string path : result) {
        cout << path << endl;
    }

    return 0;
}
