class Solution {
public:
    int n,m;
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        n=matrix.size(),m=matrix[0].size();
        
        int maxsize=0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i==0||j==0)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                    maxsize=max(dp[i][j],maxsize);
                }
            }
        }
        return pow(maxsize,2);
    }
};