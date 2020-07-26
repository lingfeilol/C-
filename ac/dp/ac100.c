class Solution {

public:
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

    int dfs(vector<vector<int>>& matrix,int x,int y,vector<vector<int>>& memo)
    {
        if(memo[x][y]!=0)
            return memo[x][y];
        ++memo[x][y];
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i],newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<matrix.size()&& newy<matrix[0].size() && matrix[newx][newy] > matrix[x][y] )
            {
                memo[x][y]=max(memo[x][y],dfs(matrix,newx,newy,memo)+1);
            }
        }
        return memo[x][y];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>> memo(row,vector<int>(col));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                memo[i][j]=dfs(matrix,i,j,memo);
            }
        }
        int ret=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ret=max(ret,memo[i][j]);
            }
        }
        return ret;
    }
};