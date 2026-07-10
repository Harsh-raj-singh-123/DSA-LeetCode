class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<int, int> mpp1;
        map<int, int> mpp2;
        vector<int> v;
        for(int i = 0; i < p.size(); i++){
            mpp2[p[i]]++;
        }
        int n = p.size();
        for(int i = 0; i < n; i++){
            mpp1[s[i]]++;
        }
        if(mpp1 == mpp2) v.push_back(0);
        int left = 0;
        for(int right = n; right < s.size(); right++){
            mpp1[s[right]]++;
            mpp1[s[left]]--;
            if(mpp1[s[left]] == 0){
                mpp1.erase(s[left]);
            }
            left++;
            if(mpp1 == mpp2){
                v.push_back(left);
            }
        }
        return v;
    }
};