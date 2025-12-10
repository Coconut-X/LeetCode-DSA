class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<long long,int,int> , vector<tuple<long long,int,int>>, greater<tuple<long long,int,int>>>minheap;

        for(int i = 0; i < points.size(); i++){
            int x = points[i][0], y = points[i][1];
            minheap.push(make_tuple(x*x*1LL+y*y*1LL, x, y));
        }
        vector<vector<int>> res;
        for(int i = 1; i <= k; i++){
            res.push_back({get<1>(minheap.top()), get<2>(minheap.top())});
            minheap.pop();
        }
        return res;
    }
};