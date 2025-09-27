class Solution {
public:
    double distance(pair<int,int>p1, pair<int,int>p2){
        return sqrt(pow((p1.first - p2.first),2)+ pow((p1.second - p2.second),2));
    }
    double area(double a, double b, double c){
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int s = points.size();
        double maxArea = 0;

        for(int i = 0; i < s - 2; i++){
            for(int j = i + 1; j < s - 1; j++){
                    double p1p2 = distance({points[i][0],points[i][1]}, {points[j][0], points[j][1]});
                for(int k = j + 1; k < s; k++){
                    double p1p3 = distance({points[i][0],points[i][1]}, {points[k][0], points[k][1]});
                    double p2p3 = distance({points[j][0],points[j][1]}, {points[k][0], points[k][1]});
                    maxArea = max(maxArea, area(p1p2,p1p3,p2p3));
                }
            }
        }

        return maxArea;
    }
};