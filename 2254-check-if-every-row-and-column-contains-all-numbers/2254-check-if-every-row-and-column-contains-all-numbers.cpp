class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
    int n=matrix.size();

    int sum=(n*(n+1))/2;
    unordered_map<int,int>mrow[n], mcol[n];
    vector<int> row(n,0), col(n,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mrow[i][matrix[i][j]] or mcol[j][matrix[i][j]] ) return false;
            mrow[i][matrix[i][j]]=1, mcol[j][matrix[i][j]]=1;
            //row[i]+=matrix[i][j];
            //col[j]+=matrix[i][j];

        }
    }

    return true;

    for(int i=0;i<n;i++)
        if(row[i]!=sum or col[i]!=sum) return false;
    return true;


    // vector<int> row(n,0), col(n,0);


    // for(int i=0;i<)
        
    }
};