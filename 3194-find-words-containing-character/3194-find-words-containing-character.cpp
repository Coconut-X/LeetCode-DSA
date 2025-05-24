class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> a;
        for(int i=0;i<words.size();i++)
        {
            if(words[i].contains(x)){
                a.push_back(i);
            }
        }

        return a;
    }
};