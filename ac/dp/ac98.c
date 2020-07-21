class Solution {
public:
    bool winnerSquareGame(int n) {
        //博弈问题
        //想赢，必须要使下一步为必输 ，相反，输的时候下一步为必赢
        vector<bool> dp(n+1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                if(dp[i-j*j]==false)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};