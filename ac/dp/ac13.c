class Solution {
public:
//dp[i][j]数组里保存的是到下标i，j处的满足正方形的个数
    int n,m;
    int countSquares(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=matrix[i][j];
                else if(matrix[i][j]==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};