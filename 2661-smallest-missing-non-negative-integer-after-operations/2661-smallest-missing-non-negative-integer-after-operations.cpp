class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                //make negative numbers positive by repeatedly adding value until >= 0
                //use this general formula instead of adding in a loop 
                nums[i] = nums[i] + value * (int)ceil((double)-nums[i] / value);
            }
            //store frequency of each remainder mod value
            freq[nums[i] % value]++;
        }

        int count = 0;
        //simulate mex counting by consuming available remainders cyclically
        while(true) {
            int mod = count % value;
            //if current remainder bucket empty, mex found
            if(freq[mod] == 0) break;
            freq[mod]--;
            count++;
        }
        return count;
    }
};
