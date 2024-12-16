class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    
    unordered_map<char,int> row[9],col[9], box[3][3];

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')  continue;

            if(row[i][board[i][j]]==1 or col[j][board[i][j]]==1 or box[i/3][j/3][board[i][j]]==1)
            return false;

            row[i][board[i][j]]=1;
            col[j][board[i][j]]=1;
            box[i/3][j/3][board[i][j]]=1;
        }

    }

    return true;

    }
};