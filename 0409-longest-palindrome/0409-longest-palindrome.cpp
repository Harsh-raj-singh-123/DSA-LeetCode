class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1) return 1;
        map<char, int> mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        int maxi = 0;
        int sum = 0;
        for(auto it : mpp){
            if(it.second % 2 == 0){
                sum += it.second;
            }
            else{
                int cnt = 0;
                cnt = (it.second / 2) * 2;;
                sum += cnt;
                maxi = max(maxi, it.second%2);
            }
        }
        sum += maxi;
        return sum;
    }
};