class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int count = 0;

        vector<int> n;
        n.push_back(nums[0]);

        for(int i = 1; i < nums.size();i++){
            if(nums[i] == n[n.size()-1]){
                continue;
            }
            n.push_back(nums[i]);
        }


        for(int i = 1; i < n.size() - 1; i++){
           
            if(n[i-1] < n[i] and n[i] > n[i+1]){
                count++;
            }
            if(n[i-1] > n[i] and n[i] < n[i+1]){
                count++;
            }
        }
        
        return count;
    }
};