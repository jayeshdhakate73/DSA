#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    int Solve(vector<vector<int>>& mat, int target, int sum, int row) {
        if (row == mat.size()) {
            return abs(target - sum);
        }

        if (dp[row][sum] != -1) { // Check if already computed
            return dp[row][sum];
        }

        int ans = INT_MAX;
        for (int col = 0; col < mat[row].size(); col++) {
            int recAns = Solve(mat, target, sum + mat[row][col], row + 1);
            ans = min(ans, recAns); // Corrected: No new variable declaration
        }
        
        return dp[row][sum] = ans; // Store result in DP table
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int maxSum = 0;
        for (auto& row : mat) {
            maxSum += *max_element(row.begin(), row.end());
        }

        dp.assign(mat.size(), vector<int>(maxSum + 1, -1)); // Initialize DP table
        return Solve(mat, target, 0, 0);
    }
};
