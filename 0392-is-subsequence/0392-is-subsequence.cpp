class Solution {
private:
    bool f(int i, int j, vector<vector<int>>& dp, string& s, string& t){
        if(i < 0) return true;  // All characters of 's' matched
        if(j < 0) return false; // Ran out of characters in 't'
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = f(i-1, j-1, dp, s, t);
        }
        return dp[i][j] = f(i, j-1, dp, s, t);
    }
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(n1-1, n2-1, dp, s, t);
    }
};