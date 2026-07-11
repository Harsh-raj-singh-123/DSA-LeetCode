class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        map<char, int> mpp1;
        for(int i = 0; i < s1.size(); i++){
            mpp1[s1[i]]++;
        }
        map<char, int> mpp2;
        int n  = s1.size();
        for(int j = 0; j < n; j++){
            mpp2[s2[j]]++;
        }
        if(mpp1 == mpp2) return true;
        int left = 0;
        for(int right = s1.size(); right < s2.size(); right++){
            mpp2[s2[right]]++;
            mpp2[s2[left]]--;
            if(mpp2[s2[left]] == 0){
                mpp2.erase(s2[left]);
            }
            left++;
            if(mpp1 == mpp2){
                return true;
            } 
        }
        return false;
    }
};