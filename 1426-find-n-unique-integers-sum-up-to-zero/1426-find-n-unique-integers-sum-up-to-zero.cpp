class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>arr(n,0);

        for(int i = 0; i < n - 1; i++){
            arr[i] = i+1;
        }
        arr[n-1] = (-1)*(n-1)*(n)/2;
        return arr;
    }
};