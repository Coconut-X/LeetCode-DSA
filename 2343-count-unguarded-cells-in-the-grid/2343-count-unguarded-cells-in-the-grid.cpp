class Solution {
public:

    int move(vector<vector<bool>>&g, vector<vector<bool>>&w,vector<vector<bool>>&v, int i, int j){
       
        int count = 0;
        int s = g.size();
        int ss = g[0].size();
        for(int x = i + 1; x < s; x++){ //down
            if(w[x][j] or g[x][j]) break;
            count+=!v[x][j];
            v[x][j] = true;
        }

        for(int x = i - 1; x >= 0; x--){ //up
            if(w[x][j] or g[x][j]) break;
            count+=!v[x][j];
            v[x][j] = true;
        }

        for(int x = j + 1; x < ss; x++){ //right
            if(w[i][x] or g[i][x]) break;
            count+=!v[i][x];
            v[i][x] = true;
        }

        for(int x = j - 1; x >= 0; x--){ //left
            if(w[i][x] or g[i][x]) break;
            count+=!v[i][x];
            v[i][x] = true;
        }

        return count;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {

        vector<vector<bool>>guards(m, vector<bool>(n,false));
        vector<vector<bool>>walls(m, vector<bool>(n,false));
        vector<vector<bool>>v(m, vector<bool>(n, false));

        for(auto &a:g) guards[a[0]][a[1]] = true;
        for(auto &a:w) walls[a[0]][a[1]] = true;

        int count = 0;
        int gw = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(walls[i][j]) gw++;
                if(guards[i][j]){
                    gw++;
                    count+=move(guards,walls,v,i,j);
                }
            }
        }

        cout<<count;
        return m*n - count - gw;

    }
};