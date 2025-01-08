class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; 

        for (int num : nums) {
            minHeap.push(num); // add current element to the heap
            if (minHeap.size() > k) {
                minHeap.pop(); // remove smallest element if heap size exceeds k
            }
        }

        return minHeap.top();
    }
};
