class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>bucket(101, 0);

        int maxelement = 0, minelement = 102;
        for(auto &n:nums){
            maxelement = max(maxelement, n);
            minelement = min(minelement,n);
            bucket[n]++;
        }
        int maxFreq = 0;
        int count = 0;

        for(int i = minelement; i <= maxelement; i++){
            if(bucket[i] > maxFreq){
                count = bucket[i];
                maxFreq = bucket[i];
            }
            else if(bucket[i] == maxFreq){
                count+=bucket[i];
            }
        }
        return count;
       
    }
};