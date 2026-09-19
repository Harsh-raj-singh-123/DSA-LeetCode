#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int solve(int person, int i, int m, vector<vector<vector<int>>>& dp, int n, vector<int>& piles) {
        if (i >= n) return 0;
        if (dp[person][i][m] != -1) return dp[person][i][m];

        int stones = 0;
        int result = (person == 1) ? 0 : INT_MAX; // Fix #3: Correct min initialization

        for (int x = 1; x <= min(n - i, 2 * m); x++) { // Fix #1: Start at x = 1
            stones += piles[i + x - 1];
            if (person == 1) {
                result = max(result, stones + solve(0, i + x, max(m, x), dp, n, piles));
            } else {
                result = min(result, solve(1, i + x, max(m, x), dp, n, piles));
            }
        }

        return dp[person][i][m] = result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // Fix #2: Size n + 1 for indices up to n
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        int m = 1;

        // Fix #4: Pass 1 for Alice's turn
        return solve(1, 0, m, dp, n, piles);
    }
};