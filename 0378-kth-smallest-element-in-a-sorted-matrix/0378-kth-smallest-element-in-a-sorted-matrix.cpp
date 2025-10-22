class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>mat;
        for(auto i:matrix) for(auto j: i) mat.push_back(j);
        sort(mat.begin(),mat.end());
        return mat[k-1];
    }
};