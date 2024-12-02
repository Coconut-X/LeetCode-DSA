class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>product;

        int prev=1;
        for(int i=0;i<nums.size();i++)
        {   
            product.emplace_back(prev);
            prev*=nums[i];
        }

        int post=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            product[i]=post*product[i];
            post*=nums[i];
        }
        return product;
    }
};