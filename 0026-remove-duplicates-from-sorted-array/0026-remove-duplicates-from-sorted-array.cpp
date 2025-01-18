class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> unique;
        vector<int> ans;

        for(auto n: nums)
        {
            if(!unique[n]) ans.push_back(n);
            unique[n]=true;
        }

        for(int i=0;i<ans.size();i++)
            nums[i]=ans[i];
        
        return ans.size();
        
    }
};