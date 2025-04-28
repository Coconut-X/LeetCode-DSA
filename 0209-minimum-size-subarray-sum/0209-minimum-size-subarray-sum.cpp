class Solution {
public:



    int minSubArrayLen(int target, vector<int>& nums) {

        //O(nlogn) solution uwu

        if(accumulate(nums.begin(),nums.end(),0) < target) return 0;

        unordered_map<int,int>prefix;
        prefix[0] = nums[0];
        prefix[-1] = 0;
        cout<<prefix[0]<<" ";
        for(int i=1; i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
            cout<<prefix[i]<<" ";
        }
        cout<<endl;

        int low = 0,  high = 0;
        bool found = false;
        int ans = INT_MAX;
        while(low<=high and high<nums.size())
        {
            if(prefix[high] - prefix[low-1] >=target){
                ans = min(ans, high - low +1);
                low++;
            }
            else{
                high++;
            }
        }


        return ans ==INT_MAX? 0: ans;
    }
};