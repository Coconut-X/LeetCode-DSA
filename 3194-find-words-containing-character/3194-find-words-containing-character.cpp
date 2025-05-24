class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> a;
        for(int i=0;i<words.size();i++)
        {
            if(find(words[i].begin(),words[i].end(),x)!=words[i].end()){
                a.push_back(i);
            }
        }

        return a;
    }
};