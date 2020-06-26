class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};//表示在0~i行里 j这个数出现过没
        int col[9][9]={0};//表示在0~i行里 j这个数出现过没
        int box[9][9]={0};//表示在0~i个小格子里 j这个数出现过没
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int n=board[i][j]-'1';
                    if(row[i][n]) return false;
                    if(col[j][n]) return false;
                    if(box[(i/3)*3+j/3][n]) return false;
                    //没出现过的话，现在出现过了，更新置为1
                    row[i][n]=1;
                    col[j][n]=1;
                    box[(i/3)*3+j/3][n]=1; 
                }
            }
        }
        return true;
    }
};