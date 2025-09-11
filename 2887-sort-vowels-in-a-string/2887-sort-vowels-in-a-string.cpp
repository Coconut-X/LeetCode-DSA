class Solution {
public:
    inline bool v(char &c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {
        string t = "";
        int n = s.size();

        for(int i  = 0; i < n; i++){
            if(v(s[i]))t+=s[i];
        }

        sort(t.begin(),t.end());
        
        for(int i = 0, j = 0; i < n; i++){
            if(v(s[i]))
                s[i] = t[j++];
        }

        return s;
        
    }
};