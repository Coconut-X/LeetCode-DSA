class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        stable_sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        for (int i = 0; i < n - 1; i++) {
            bool v = false, h = false; //vertical and horizontal found
            int max_y = INT_MIN, closest_x = INT_MAX; //max Y till now
            pair<int,int> maxYPoint = {INT_MAX, INT_MAX}, closestXPoint = {INT_MAX, INT_MAX};

            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0] && !v) {
                    maxYPoint = {points[j][0], points[j][1]};
                    v = true;
                    count++;
                    if (points[j][1] <= points[i][1]) max_y = max(max_y, points[j][1]);
                }
                else if (points[i][1] == points[j][1] && !h) {
                    closestXPoint = {points[j][0], points[j][1]};
                    closest_x = min(closest_x, points[j][0]);
                    h = true;
                    count++;
                    if (points[j][1] <= points[i][1]) max_y = max(max_y, points[j][1]);
                }
                else if (points[j][1] <= points[i][1] and points[j][1] > max_y) {
                        count++;
                        max_y = max(max_y, points[j][1]);
                }
            }
        }

        return count;
    }
};
