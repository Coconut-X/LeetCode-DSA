class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>bucket(101, 0);

        for(auto &n:nums){
            bucket[n]++;
        }
        int maxFreq = 0;
        int count = 0;

        for(int i = 0; i <= 100; i++){
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