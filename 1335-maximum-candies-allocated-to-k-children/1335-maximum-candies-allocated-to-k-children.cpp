class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        int left=1;
        int right=*max_element(candies.begin(), candies.end());

        int ans=0;

        auto valid=[&](int n){
            long long count=0;
            for(auto c: candies){
                count+=c/n;
            }
            return count>=k; 
        };

        while(left<=right){
            int mid=left + (right-left)/2;

            if(valid(mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;    
            }
        }

        return ans;
        
    }
};