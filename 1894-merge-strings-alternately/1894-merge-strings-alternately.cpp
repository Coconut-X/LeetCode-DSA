class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged=""; int i=0;
        for(;i<min(word1.size(), word2.size());i++)
            merged+=word1[i], merged+=word2[i];
        
        while(i<word1.size())                   //none or only one of below while loops will run
            merged+=word1[i++];

        while(i<word2.size())
            merged+=word2[i++];
        
        return merged;
    }
};