class Solution {
    vector<vector<string>> ret;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));//初始化棋盘  '.' 表示空，'Q' 表示皇后
        dfs(board,0);
        return ret;
    }
// 路径：board 中小于 row 的那些行都已经成功放置了皇后
// 选择列表：第 row 行的所有列都是放置皇后的选择
// 结束条件：row 超过 board 的最后一行
    void dfs(vector<string>& board,int row)
    {
        if(row==board.size())  //结束条件
        {
            ret.push_back(board);
            return ;
        }
        for(int j=0;j<board[0].size();j++)
        {
            // 排除不合法选择、剪枝
            if (!isValid(board, row, j)) //当前位置的坐标不满足放置规则
                continue;
            board[row][j]='Q';
            dfs(board,row+1);
            board[row][j]='.';
        }
    }
    bool isValid(vector<string>& board,int row,int col)
    {
        //检查列是否满足
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col]=='Q')
                return false;
        }
        //检查对角线，且只需要检查左上角即可
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //检查副对角线，只检查右上角
        for(int i=row-1,j=col+1;i>=0&&j<board[0].size();i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
};