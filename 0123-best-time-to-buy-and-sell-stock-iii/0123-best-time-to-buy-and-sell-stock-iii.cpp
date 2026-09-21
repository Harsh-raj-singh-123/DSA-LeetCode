class Solution {
// private:
//     int f(int ind, vector<int>& prices, vector<vector<vector<long>>>& dp, int buy, int cap){
//         int m = prices.size();
//         if(ind == m) return 0;
//         if(cap == 0) return 0;
//         if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
//         int profit;
//         if(buy){
//             profit = max(-prices[ind] + f(ind+1, prices, dp, 0, cap), 0 + f(ind+1, prices, dp, 1, cap));
//             dp[ind][buy][cap] = profit;
//         }
//         else{
//             profit = max(prices[ind] + f(ind+1, prices, dp, 1, cap-1), 0 + f(ind+1, prices, dp, 0, cap));
//             dp[ind][buy][cap] = profit;
//         }
//         return dp[ind][buy][cap] = profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        // int m = prices.size();
        // vector<vector<vector<long>>> dp(m, vector<vector<long>>(2, vector<long>(3, -1)));
        // return f(0, prices, dp, 1, 2);
    int lelo1=INT_MAX, bechdo1=0, lelo2=INT_MAX, bechdo2=0;
for(int i=0;i<prices.size();i++){

lelo1=min(lelo1,prices[i]);
bechdo1=max(bechdo1, prices[i]-lelo1);

lelo2=min(lelo2,prices[i]-bechdo1);
bechdo2=max(bechdo2, prices[i]-lelo2);



}

  return bechdo2;

    }
};