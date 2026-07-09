class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        for(int i = 0; i < s.size(); i++){
            string word = "";
            while(i < s.size() && s[i] == ' ')
                i++;
            while(i < s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            if(word != "")    
                v.push_back(word);
        }
        string str = "";
        for(int i = v.size()-1; i >= 0; i--){
            str += v[i];
            if(i != 0)
                str += " ";
        }
        return str;
    }
};