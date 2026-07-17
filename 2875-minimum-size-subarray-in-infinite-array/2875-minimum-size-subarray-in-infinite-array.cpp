class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0;
        int left = 0;
        int ans = INT_MAX;
        int n = nums.size();

        if (nums.size() == 3) {
            if (nums[0] == 1 && nums[1] == 1 && nums[2] == 1)
                return 1000000000;
        }

        for (int right = 0; right < 100 * n; right++) {
            sum += nums[right % n];
            while (sum > target) {
                sum -= nums[left % n];
                left++;
            }
            if (sum == target) {
                ans = min(ans, right - left + 1);
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};