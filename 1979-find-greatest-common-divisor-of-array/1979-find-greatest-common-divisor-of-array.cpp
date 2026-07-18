class Solution {
private:
    int gcd(int x, int y){
        if(x == 0) return y;
        if(y == 0) return x;
        return gcd(y, x%y);
    }
public:
    int findGCD(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int x  = nums[0];
        int y = nums[nums.size()-1];
        return gcd(x, y);
    }
};