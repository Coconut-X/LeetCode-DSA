class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>m;
        vector<vector<string>> all;
        for(int i=0;i<strs.size();i++)
        {
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end());
            m[sorted].push_back(strs[i]);
        }

        for(auto i: m)
            all.push_back(i.second);
        
        return all;


    }
};