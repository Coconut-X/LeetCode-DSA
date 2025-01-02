class Solution {
public:


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        unordered_map<int,int> m;

        auto vowel=[](char curr){
            return curr == 'a' or curr == 'e' or curr == 'i' or curr == 'o' or curr == 'u';
        };

        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string curr=words[i];
            m[i]=((vowel(curr[0]) and vowel(curr[curr.size()-1]))? ++count: count);
        }

        vector<int> ans;
        for(int i=0; i<queries.size();i++)
        {
            int s=queries[i][0];
            int e=queries[i][1];

            int sum=m[e]-m[s-1];
           
            ans.push_back(sum);
        }

        return ans;
        
    }
};