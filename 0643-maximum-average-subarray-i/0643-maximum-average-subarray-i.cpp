class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        unordered_map<int,double> sum;
        double m=INT_MIN;  

        for(int i=0;i<nums.size();i++)
            sum[i]=(i==0? nums[i]: sum[i-1]+nums[i]);

        for(int i=0;i+k - 1<nums.size();i++)
            m=max(m, (sum[i + k - 1] - sum[i-1]));

        return m/k;
        
    }
};