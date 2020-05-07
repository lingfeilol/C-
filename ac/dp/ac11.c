class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int dp[row][col];
        dp[0][0]=grid[0][0];
        for(int i=1;i<row;i++)//初始化最左边哪一列，只能向下走
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<col;j++)//初始化最上边哪一行，只能向右边走
        {
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];//向下向右的最小选择
        return dp[row-1][col-1];
    }
};