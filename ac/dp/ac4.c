class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int j=1;j<=m;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])//字符相同不做操作，下一个状态值不变
                    dp[i][j]=dp[i-1][j-1];
                else//不同了，考虑那种操作
                {
                    dp[i][j]=Min(dp[i-1][j]+1, //删  我删去一个再和你匹配，
                                dp[i][j-1]+1,  //增  我插入一个和你一样的来匹配，
                                dp[i-1][j-1]+1);//改 我替换一个和你一样的来匹配，
                }
            }
        }
        return dp[n][m];

    }
    int Min(int a,int b,int c)
    {
       return min(a,min(b,c));
    }
};