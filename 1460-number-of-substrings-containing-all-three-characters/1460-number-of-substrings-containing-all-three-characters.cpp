class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mep;
        int l = 0, count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            mep[s[i]]++;
            
            while (mep['a'] && mep['b'] && mep['c']) { 
                count += s.size() - i; 
                mep[s[l]]--; 
                l++;  
            }
            
        }
        
        return count;
    }
};
