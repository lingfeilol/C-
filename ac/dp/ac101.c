class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i-j;j++)
            {
                dp[i]=max(dp[i],j*(i-j)); //不拆
                dp[i]=max(dp[i],j*dp[i-j]);  //拆
            }
        }
        return dp[n];
    }
};