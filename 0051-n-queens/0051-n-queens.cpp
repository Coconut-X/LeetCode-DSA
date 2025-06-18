class Solution {
public:

vector<vector<string>> result; 

void addResult(vector<vector<char>>& vec){
    vector<string> rowStrings; 
    for(int i = 0; i < vec.size(); i++){
        string s = "";
        for(int j = 0; j < vec[i].size(); j++){ 
            s += vec[i][j];
        }
        rowStrings.push_back(s); 
    }

    result.push_back(rowStrings); 
}

void removeQueen(vector<vector<char>>&board,unordered_map<int,bool>&rows, unordered_map<int,bool>&cols,unordered_map<int,bool>&mainDiagonal, unordered_map<int,bool>&antiDiagonal, int r, int c){
    board[r][c] = '.';
    rows[r]= false;
    cols[c] = false;
    mainDiagonal[r-c] = false;
    antiDiagonal[r+c] = false;
}

void setQueen(vector<vector<char>>&board,unordered_map<int,bool>&rows, unordered_map<int,bool>&cols,unordered_map<int,bool>&mainDiagonal, unordered_map<int,bool>&antiDiagonal, int r, int c){
    board[r][c] = 'Q';
    rows[r]= true;
    cols[c] = true;
    mainDiagonal[r-c] = true;
    antiDiagonal[r+c] = true;
}

bool isValid(unordered_map<int,bool>&rows, unordered_map<int,bool>&cols,unordered_map<int,bool>&mainDiagonal, unordered_map<int,bool>&antiDiagonal, int r, int c){
    return 0 == rows[r]+cols[c]+mainDiagonal[r-c]+antiDiagonal[r+c];
}

void brute(vector<vector<char>>&board, unordered_map<int,bool>&rows, unordered_map<int,bool>&cols,unordered_map<int,bool>&mainDiagonal, unordered_map<int,bool>&antiDiagonal, int r)
{

    //maindiagonal=row-col
    //anti diagonal = row+col;

    if(r==board.size()){
        return;
    }

    for(int col = 0; col<board.size();col++){
        
        if(isValid(rows,cols,mainDiagonal, antiDiagonal,r,col)){
            setQueen(board,rows,cols,mainDiagonal, antiDiagonal, r, col);
            if(r == board.size()-1){
                addResult(board);
            }
            brute(board, rows, cols, mainDiagonal, antiDiagonal,r+1);
            removeQueen(board,rows,cols,mainDiagonal, antiDiagonal, r, col);
        }
    }
}


    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        unordered_map<int,bool> rows; unordered_map<int,bool> cols; unordered_map<int,bool> mainDiagonal; unordered_map<int,bool> antiDiagonal;
        brute(board, rows, cols, mainDiagonal, antiDiagonal,0);
        
        return result;

    }
};