class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;

        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }

        if (v.size() < 2)
            return 0;

        int maxpro = 0;

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                maxpro = max(maxpro, v[i] * v[j]);
            }
        }

        return maxpro;
    }
};