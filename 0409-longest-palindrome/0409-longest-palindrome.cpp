class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        vector<char> chars;
        for(auto c:s)
            if(!freq[c]++)  chars.push_back(c);
        
        int maxOdd = 0, maxEven = 0;
        char odd = ' ';
        for(auto c: chars){
            if(freq[c]%2==1){ //if odd
                if(freq[c]>=maxOdd)
                    odd = c, maxOdd = freq[c];
            }
            else
                maxEven+=freq[c];
        }

        for(auto c:chars)
            if(freq[c]%2==1 and c!=odd)
                maxEven+=freq[c]-1;

        return maxOdd+maxEven;
    }
};