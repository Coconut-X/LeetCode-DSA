class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(char &c:word) if(c < 'a') count++;
        return !count or count==word.size() or (count == 1 and word[0] < 'a');
    }
};