class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //unordered_map<pair<int,int>,int,hash<pair<int,int>>> freq;
        unordered_map<int,int>freq;
        vector<int> prefix(nums.size(),0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(auto p:prefix)cout<<p<<" ";
        
        int count =0;
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==k) count++;
            if(freq[prefix[i]-k]){
                count+=freq[prefix[i]-k];
            }
            freq[prefix[i]]++;
        }
        return count;
    }
};