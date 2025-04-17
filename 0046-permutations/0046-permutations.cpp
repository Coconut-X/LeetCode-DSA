class Solution {
public:

    void brute(vector<int>& nums, unordered_map<int,bool> mep, vector<vector<int>>&perms, vector<int> perm)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(!mep[nums[i]])
            {
                perm.push_back(nums[i]);
                mep[nums[i]]=true;
                if(perm.size()==nums.size())
                {
                    perms.push_back(perm);
                    return;
                }
                brute(nums,mep,perms,perm);
                mep[nums[i]]=false;
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>perms;
        unordered_map<int,bool>mep;
        vector<int>perm;
       
        brute(nums,mep,perms,perm);

        return perms;
        
    }
};