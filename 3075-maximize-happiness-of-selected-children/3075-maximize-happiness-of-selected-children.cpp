class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long count = 0;
        for(int i = 0; i < k; i++)
            count += max(0,happiness[i] - i);
        return count;
    }
};