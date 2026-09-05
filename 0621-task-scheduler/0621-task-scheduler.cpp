class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Count how many tasks have maximum frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) maxCount++;
        }

        // Calculate minimum intervals
        int intervals = (maxFreq - 1) * (n + 1) + maxCount;

        // Answer is the maximum of total tasks and calculated intervals
        return max((int)tasks.size(), intervals);
    }
};