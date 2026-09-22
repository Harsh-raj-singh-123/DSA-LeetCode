class Solution{
private:
    void solve(int i, string& s, int k, vector<string>& v, int n, string& s1, vector<bool>& visited){
        if(i == n){
            v.push_back(s1);
            return;
        }
        for(int j = 1; j <= n; j++){
            if(!visited[j]){
                visited[j] = true;
                s1.push_back(j + '0');
                solve(i+1, s, k, v, n, s1, visited);
                s1.pop_back();
                visited[j] = false;
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++){
            s += i + '0';
        }

        int fact = 1;
        int x = n;
        while(x > 0){
            fact = fact * x;
            x--;
        }
        vector<string> v; 
        vector<bool> visited(n+1, false);
        string s1 = "";
        solve(0, s, k, v, n, s1, visited);
        return v[k-1];
    }
};