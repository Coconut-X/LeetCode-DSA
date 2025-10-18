class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MAX;
        int minrow, maxrow;

        for(int i = 0; i < a.size(); i++){
            int first = a[i][0], last = a[i].back();
            //find first and second smallert
            if(first < min1) min2 = min1, min1 = first, minrow = i;
            else if(first < min2) min2 = first;

            //find first and second largest
            if(last > max1) max2 = max1, max1 = last, maxrow = i;
            else if(last > max2) max2 = last;
        }

        if(minrow != maxrow) return max1 - min1;
        return max(max1 - min2, max2 - min1); 
    }
};