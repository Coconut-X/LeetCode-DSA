class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int neg=0,pos=0;
        int i=0;
        
            while(i<nums.size() and nums[i]<0){
                i++;
                neg++;
            }
            while(i<nums.size() and nums[i]==0){
                pos++;
                i++;
            }
           
        int n=nums.size();

        return max(neg,n-pos -neg);
    }
};