class Solution {
public:


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        unordered_map<int,int> prefix;

        auto vowel=[](char curr){
            return curr == 'a' or curr == 'e' or curr == 'i' or curr == 'o' or curr == 'u';
        };

        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string curr=words[i];
            prefix[i]=((vowel(curr[0]) and vowel(curr[curr.size()-1]))? ++count: count);
        }

        vector<int> ans;
        
        for(auto q:queries)
            ans.push_back(prefix[q[1]]-prefix[q[0]-1]);

        return ans;
    }
};