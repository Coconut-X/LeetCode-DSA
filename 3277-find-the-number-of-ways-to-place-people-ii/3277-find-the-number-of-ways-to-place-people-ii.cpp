class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        stable_sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        for (int i = 0; i < n - 1; i++) {
            bool v = false, h = false;
            // closest_y holds the maximum y seen so far among points between i and current j
            // that are <= points[i].y. Initialize to very small so first valid y passes.
            int closest_y = INT_MIN, closest_x = INT_MAX;
            pair<int,int> closestYPoint = {INT_MAX, INT_MAX}, closestXPoint = {INT_MAX, INT_MAX};

            for (int j = i + 1; j < n; j++) {
                // vertical candidate (same x) — count only the first (closest) one
                if (points[i][0] == points[j][0] && !v) {
                    closestYPoint = {points[j][0], points[j][1]};
                    v = true;
                    cout << "[" << points[i][0] << "," << points[i][1] << "], [" 
                         << points[j][0] << "," << points[j][1] << "]" << endl;
                    count++;
                    // update closest_y with this point if it's <= A.y (it will be)
                    if (points[j][1] <= points[i][1]) closest_y = max(closest_y, points[j][1]);
                }
                // horizontal candidate (same y) — count only the first (closest) one
                else if (points[i][1] == points[j][1] && !h) {
                    closestXPoint = {points[j][0], points[j][1]};
                    closest_x = min(closest_x, points[j][0]);
                    h = true;
                    cout << "[" << points[i][0] << "," << points[i][1] << "], [" 
                         << points[j][0] << "," << points[j][1] << "]" << endl;
                    count++;
                    // update closest_y too (same y is on the border and blocks diagonals above it)
                    if (points[j][1] <= points[i][1]) closest_y = max(closest_y, points[j][1]);
                }
                else {
                    // diagonal candidate: must be below-or-equal to A.y
                    if (points[j][1] <= points[i][1]) {
                        // valid iff no previously-seen point in (i, j) had y in [points[j].y, points[i].y]
                        // i.e. points[j].y must be strictly greater than closest_y
                        if (points[j][1] > closest_y) {
                            cout << "[" << points[i][0] << "," << points[i][1] << "], [" 
                                 << points[j][0] << "," << points[j][1] << "]" << endl;
                            count++;
                        }
                        // update closest_y with this j so later j's know about it
                        closest_y = max(closest_y, points[j][1]);
                    }
                }
            }
        }

        return count;
    }
};
