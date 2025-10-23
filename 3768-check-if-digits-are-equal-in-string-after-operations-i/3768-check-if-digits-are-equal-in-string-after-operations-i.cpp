class Solution {
public:
    bool hasSameDigits(string &s) {
        if(s.size()==2){
            return s[0]==s[1];
        }
        string t = "";
        for(int i = 0; i < s.size() - 1; i++){
            int a = s[i] - '0', b = s[i+1] - '0';
            int res = (a+b)%10;
            t+=(res + '0');
        }
        return hasSameDigits(t);
    }
};