class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for(auto& row: image)
        {    
            reverse(row.begin(), row.end());
            transform(row.begin(), row.end(), row.begin(), [](int x) {
            return x ^ 1;
            });
        }

        return image;  
    }
};