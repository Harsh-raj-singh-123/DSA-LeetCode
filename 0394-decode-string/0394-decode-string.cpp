class Solution{
private:
    string solve(int& i, string& s){
        string result = "";
        int num = 0;
        while(i < s.size()){
            char c = s[i];
            if(isdigit(c)){
                num = num*10 + (c-'0');
                i++;
            }
            else if(c == '['){
                i++;
                string inner = solve(i, s);
                for(int k = 0; k < num; k++){
                    result += inner;
                }
                num = 0;
            }
            else if(c == ']'){
                i++;
                return result;
            }
            else{
                result += c;
                i++;
            }
        }
        return result;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
    }
};