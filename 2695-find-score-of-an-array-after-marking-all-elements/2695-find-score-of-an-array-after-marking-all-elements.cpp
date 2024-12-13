class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false); 
        long long score = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; //make min heap using greater 

        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i}); //store the num along with its index 
        }

        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();
            if (marked[index]) continue;
            score += value;
            marked[index] = true;

            if (index > 0) marked[index - 1] = true; 
            if (index < n - 1) marked[index + 1] = true; 
        }

        return score;
    }
};
