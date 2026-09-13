class Solution {
public:
    string removeKdigits(string num, int k){
        int n = num.size();
        stack<int> st;
        st.push(num[0] - '0');
        for (int i = 1; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > (num[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        string s = "";
        while (!st.empty()) {
            s += char(st.top() + '0');
            st.pop();
        }
        reverse(s.begin(), s.end());

        int i = 0;
        while (i < s.size() && s[i] == '0')
            i++;

        s = s.substr(i);
        return s.empty() ? "0" : s;
    }
};