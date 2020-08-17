class Solution {
public:
    typedef pair<int,int> PII;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    queue<PII> q;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int b=image[sr][sc];
        // if(b!=newColor)
        //     dfs(image,sr,sc,newColor,b);
        if(b!=newColor)
        {
            q.push({sr,sc});
            bfs(image,b,newColor);
        }
        return image;
    }
    void dfs(vector<vector<int>>& board, int x,int y,int k,int b)
    {
        if(board[x][y]==b)
        {
            board[x][y]=k;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && nx<board.size()&& ny>=0 && ny<board[0].size())
                {
                    dfs(board,nx,ny,k,b);
                }
            }
        }
    }
    void bfs(vector<vector<int>>& board,int b,int newcolor)
    {
        while(!q.empty())
        {
            auto tmp=q.front();
            q.pop();
            int x=tmp.first,y=tmp.second;
            if(board[x][y]==b)
            {
                board[x][y]=newcolor;
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx>=0 && nx< board.size()&& ny>=0 && ny < board[0].size()&& board[nx][ny]==b)
                    q.push({nx,ny});
                }
            }
        }
    }
};