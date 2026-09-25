class Solution{
private:
    void solve(int k, int n, int start, vector<int>& level, vector<vector<int>>& ans, int sum){
        if(k == level.size()){
            if(sum == n){
                ans.push_back(level);
            }
            return;
        }
        if(sum > n) return;

        for(int i = start; i <= 9; i++){
            level.push_back(i);
            solve(k, n, i+1, level, ans, sum+i);
            level.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> level;
        solve(k, n, 1, level, ans, 0);
        return ans;
    }
};