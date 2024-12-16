class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0;                  
        int j = 0;                  
        int maximum = 0;           
        
        while (j < s.size()) 
        {
            mp[s[j]]++;

            while (mp[s[j]] > 1) 
            {
                mp[s[i]]--;
                i++;
            }
            maximum = max(maximum, j - i + 1);
            j++;
        }

        return maximum;
    }
};
