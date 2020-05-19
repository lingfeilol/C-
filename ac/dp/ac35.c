class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> ret;
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        for(int i=0;i<row;i++)//列初始化
        {
            if(obstacleGrid[i][0]==1)
                break;
            dp[i][0]=1;
        }
        for(int j=0;j<col;j++)//行初始化
        {
            if(obstacleGrid[0][j]==1)
                break;
            dp[0][j]=1;
        }
        vector<bool> used;
        for(int i=1;i<row;i++)//找路径
        {
            for(int j=1;j<col;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//不用算总的多少条路，而是选择的最大的，这样有个规范后，最后就可以反退回来路径
                }
            }
        }
        if(dp[row-1][col-1]==0) return ret;//说明没有走到右下

        //复原当时的场景，回退
        int r=row-1,c=col-1;
        while(r|| c)
        {
            ret.push_back({r,c});
            int up=0;
            if(r>0) up=dp[r-1][c]; //从上面下来的

            int left=0;
            if(c>0) left=dp[r][c-1];//从左边过来的
            //判断一下，两者大小，就知道当初是选的谁了
            if(up>=left)//当初是选的上面下来的
                r--;
            else //选的左边来的
                c--;
        }
        ret.push_back({0,0});//起点放进去；
        reverse(ret.begin(),ret.end());
        return ret;
    }
};