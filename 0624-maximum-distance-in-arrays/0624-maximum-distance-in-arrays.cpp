class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MAX;
        int minrow, maxrow;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i][0] < min1) min2 = min1, min1 = a[i][0], minrow = i;
            else if(a[i][0] < min2) min2 = a[i][0];
            if(a[i][a[i].size() - 1] > max1) max2 = max1, max1 = a[i][a[i].size() - 1], maxrow = i;
            else if(a[i][a[i].size() - 1] > max2) max2 = a[i][a[i].size() - 1];
        }

        if(minrow != maxrow) return max1 - min1;
        return max(max1 - min2, max2 - min1); 
    }
};