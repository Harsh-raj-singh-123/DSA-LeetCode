class Solution {
private:
    void solve(int ind, vector<vector<int>>& ans, int target,vector<int>& a, vector<int>& candidates) {
        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(a);
            }
            return;
        }
        if (candidates[ind] <= target){
            a.push_back(candidates[ind]);
            solve(ind, ans, target - candidates[ind], a, candidates);
            a.pop_back();
        }
        solve(ind + 1, ans, target, a, candidates);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(0, ans, target, a, candidates);
        return ans;
    }
};