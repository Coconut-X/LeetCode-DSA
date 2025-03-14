class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid;  // Count how many children can receive `mid` candies
            if (count >= k) return true;  // If enough children are served, return true
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if (accumulate(candies.begin(), candies.end(), 0LL) < k) return 0;  // If total candies < k, return 0

        int left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDistribute(candies, k, mid)) {
                ans = mid;  // Try for a larger `mid`
                left = mid + 1;
            } else {
                right = mid - 1;  // Reduce `mid` if not possible
            }
        }

        return ans;
    }
};
