class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int ans = 0;
        for(auto& c:s){
            if(c=='R')count++;
            else count--;
            ans+=count==0;
        }
        return ans;
    }
};