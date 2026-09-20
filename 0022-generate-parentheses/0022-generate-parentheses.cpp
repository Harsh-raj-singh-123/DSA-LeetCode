class Solution{
private:
    void gene(int o, int c, vector<string>& v, string& s){
        if(o == 0 && c == 0){
            v.push_back(s);
            return;
        }
        if(o > 0){
            s.push_back('(');
            gene(o-1, c, v, s);
            s.pop_back();
        }
        if(c > o){
            s.push_back(')');
            gene(o, c-1, v, s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s  = "";
        gene(n, n, v, s);
        return v;
    }
};