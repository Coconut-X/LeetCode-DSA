class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(), happiness.end(), greater<int>());

        int kids = 0;
        int min = happiness[happiness.size() - 1];
        long long count = 0;
        for(int i = 0; i < k; i++){
            //if(min - kids < 0) break;
            long long diff = happiness[i] - kids;
            if(diff >= 0)
                count += happiness[i] - kids;
            kids++;
        }
        return count;
    }
};