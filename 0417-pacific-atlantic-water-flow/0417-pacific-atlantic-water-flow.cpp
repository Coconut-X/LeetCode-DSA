class Solution {
public:
    bool valid(int n, int m, int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    void flow(vector<vector<int>>& h, vector<vector<bool>>& v, int n, int m, int r, int c) {
        if (!valid(n, m, r, c) || v[r][c]) return;
        v[r][c] = true;

        if (valid(n, m, r - 1, c) && h[r - 1][c] >= h[r][c]) flow(h, v, n, m, r - 1, c);
        if (valid(n, m, r + 1, c) && h[r + 1][c] >= h[r][c]) flow(h, v, n, m, r + 1, c);
        if (valid(n, m, r, c + 1) && h[r][c + 1] >= h[r][c]) flow(h, v, n, m, r, c + 1);
        if (valid(n, m, r, c - 1) && h[r][c - 1] >= h[r][c]) flow(h, v, n, m, r, c - 1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) flow(h, pacific, n, m, 0, i);
        for (int i = 0; i < n; i++) flow(h, pacific, n, m, i, 0);

        for (int i = 0; i < n; i++) flow(h, atlantic, n, m, i, m - 1);
        for (int i = 0; i < m; i++) flow(h, atlantic, n, m, n - 1, i);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
