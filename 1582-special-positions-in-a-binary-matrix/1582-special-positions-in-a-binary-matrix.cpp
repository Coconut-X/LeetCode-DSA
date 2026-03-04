class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowsum(m,0);
        vector<int> colsum(n,0);
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                rowsum[i]+=mat[i][j];
                colsum[j]+=mat[i][j];
            }
        }
        int count = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1 and rowsum[i] == 1 and colsum[j] == 1) count++;
            }
        }
        
        return count;
    }
};