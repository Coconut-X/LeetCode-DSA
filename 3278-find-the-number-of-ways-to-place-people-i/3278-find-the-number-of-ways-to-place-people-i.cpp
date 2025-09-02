// class Solution {
// public:
//     int numberOfPairs(vector<vector<int>>& points) {
//         int n = points.size();
//         int count = 0;
//         for(int i = 0; i < n ; i++){
            
//             for(int j = 0; j < n; j++){
//                 if(i==j) continue;
//                 if (points[i][0] < points[j][0] && points[i][1] > points[j][1]){

//                     bool exist = false;
//                     for(int k = i+1; k < j; k++){
//                         if (k == i || k == j) continue;
//                         if (points[k][0] >= points[i][0] && points[k][0] <= points[j][0] && 
//                             points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
//                             exist = true;
//                             break;
//                         }
//                     }
//                     if(!exist){
//                         count++;
//                     }
//                 }
//             }
//         }   

      
//         return count;
//     }
// };

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {          // A = points[i]
            for (int j = 0; j < n; ++j) {      // B = points[j]
                if (i == j) continue;

                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];

                // A is upper-left of B; lines allowed (same x or same y)
                if (ax <= bx && ay >= by) {
                    bool empty = true;
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int cx = points[k][0], cy = points[k][1];

                        // Rectangle (or line) is inclusive on borders
                        if (cx >= ax && cx <= bx && cy <= ay && cy >= by) {
                            empty = false;
                            break;
                        }
                    }
                    if (empty) ++count;
                }
            }
        }
        return count;
    }
};
