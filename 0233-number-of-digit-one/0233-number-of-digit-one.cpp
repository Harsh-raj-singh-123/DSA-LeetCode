class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        
        // i represents the place value: 1 (units), 10 (tens), 100 (hundreds)...
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            
            // 1. Contribution from complete groups of size (10 * i)
            count += (n / divider) * i;
            
            // 2. Contribution from the remaining incomplete group
            long long remainder = n % divider;
            count += min(max(remainder - i + 1, 0LL), i);
        }
        
        return count;
    }
};