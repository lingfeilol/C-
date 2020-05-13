class Solution {
    int count;
    int used[10][10];
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};//方向
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)//先把所有烂橘子入队列，之后好围绕着展开感染
                    q.push({i,j});
            }
        }
        int size=0;
        while(!q.empty())
        {
            size=q.size();//和二叉树层序一样的逻辑,一层一层处理
            for(int i=0;i<size;i++)
            {
                auto tmp=q.front();
                q.pop();
                for(int j=0;j<4;j++)//控制方向
                {
                    int nx=tmp.first+dx[j];
                    int ny=tmp.second+dy[j];
                    if(nx>=0&&nx<n&& ny>=0&&ny<m&& grid[nx][ny]==1)//可以感染
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});//并且入队列
                    }
                }              
            }
             //各个方向走完一步后，可以加一分钟了
            if(!q.empty())//但是也要考虑最后一步的情况，可能最后都是到了边界的情况，没有被感染者入队，也就没必要再加一分钟时间了
            {
                count++;
            }
        }
        for(int i=0;i<n;i++)//最后在判断有没新鲜的
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
    }
};