class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(),0);
        sort(capacity.begin(), capacity.end(),greater<int>());

        int count = 0;
        int prefix = 0;
        for(auto &c: capacity){
            prefix+=c;
            count++;
            if(prefix>=sum) return count;
        }
        return count;
    }
};