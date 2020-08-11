class Solution {
public:
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    void solve(vector<vector<char>>& board) {
        if(board.empty()) 
            return ;
        //找到每个入口，标记可以延申的坐标， 最后再把没有标记的全部设置为x
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                bool flag= (i==0|| j==0|| i==n-1|| j==m-1);
                if( flag && board[i][j]=='O')
                    dfs(board,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0|| j==0 || i==n-1|| j==m-1)
                {
                     continue;
                }
                else
                {
                    if(board[i][j]=='g')
                        board[i][j]='O';
                    else 
                        board[i][j]='X';
                }
            }
        }

    }
    void dfs(vector<vector<char>>& board,int x,int y,int n,int m)
    {
        for(int i=0;i<4;i++)
        {
            int new_x=x+dx[i], new_y=y+dy[i];
            if(new_x>0 && new_x<n-1 && new_y>0 && new_y<m-1 && board[new_x][new_y]=='O')
            {
                board[new_x][new_y]='g';
                dfs(board,new_x,new_y,n,m);
            }
        }
    }
};