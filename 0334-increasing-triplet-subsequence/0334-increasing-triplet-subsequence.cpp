class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first=INT_MAX, second=INT_MAX;

        for(auto mid: nums)
        {
            if(first >= mid) first=mid;
            else if(second >= mid) second=mid;
            else 
                return true;
        }

        return false;
        
    }
};