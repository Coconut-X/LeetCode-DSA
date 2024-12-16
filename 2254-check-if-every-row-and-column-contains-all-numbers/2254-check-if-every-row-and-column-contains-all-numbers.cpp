class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
    
    int n=matrix.size();
    unordered_map<int,int>mrow[n], mcol[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mrow[i][matrix[i][j]] or mcol[j][matrix[i][j]] ) return false;
            mrow[i][matrix[i][j]]=1, mcol[j][matrix[i][j]]=1;
        }
    }

    return true;
    }
};