class Solution {
public:
//有障碍物，那就说明这个格子法到达，路径数位0
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        vector<vector<long long>> dp(row,vector<long long>(col));
        for(int i=0;i<row;i++)//第一列的特殊情况
        {
            if(obstacleGrid[i][0]==1)//有障碍物了
                break;
            dp[i][0]=1;
        }
        for(int j=0;j<col;j++)
        {
            if(obstacleGrid[0][j]==1)//有障碍物
                break;
            dp[0][j]=1;
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};