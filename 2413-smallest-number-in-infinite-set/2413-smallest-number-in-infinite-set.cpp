class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> inHeap;
    int nextSmallest;

    SmallestInfiniteSet() {
        nextSmallest = 1; 
    }
    
    int popSmallest() {
        int smallest;
        if (!minHeap.empty() && minHeap.top() < nextSmallest) {
            smallest = minHeap.top();
            minHeap.pop();
            inHeap.erase(smallest);
        } else {
            smallest = nextSmallest;
            nextSmallest++;
        }
        return smallest;
    }
    
    void addBack(int num) {
        if (num >= nextSmallest || inHeap.count(num)) return; // no duplicates
        minHeap.push(num);
        inHeap.insert(num);
    }
};
