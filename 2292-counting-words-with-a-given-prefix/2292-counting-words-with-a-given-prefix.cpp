class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0, prefSize=pref.size();
        for(auto word: words)
            if(pref==word.substr(0,prefSize))
                count++;

        return count;
    }
};