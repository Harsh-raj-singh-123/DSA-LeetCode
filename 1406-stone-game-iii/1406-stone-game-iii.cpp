class Solution{
private:
    int solve(int person, vector<int>& stoneValue, int i, int n, vector<vector<int>>& dp){
        if(i >= n) return 0;
        if(dp[person][i] != -1e9) return dp[person][i];
        int stones = 0;
        int result;
        if(person == 0) result = -1e9;
        else result = 1e9;
        for(int k = 0; k < min(3, n-i); k++){
            stones += stoneValue[i+k];
            if(person == 0){
                result = max(result, stones + solve(1, stoneValue, i+k+1, n, dp));
            }
            else{
                result = min(result, solve(0, stoneValue, i+k+1, n, dp));
            }
        }
        return dp[person][i] = result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue){
        int n = stoneValue.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, -1e9));
        int x = solve(0, stoneValue, 0, n, dp);
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int y = sum - x; 
        if (x > y) return "Alice";
        else if (y > x) return "Bob";
        return "Tie";
    }
};