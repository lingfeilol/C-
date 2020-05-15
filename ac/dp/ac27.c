class Solution {
public:
    bool divisorGame(int N) {
        bool dp[1010]={false};
        dp[1]=false;
        dp[2]=true;
        for(int i=3;i<=N;i++) //被除数
        {
            for(int j=1;j<i;j++) //枚举除数
            {
                if(dp[i-j]==false && (i%j==0))//由于是博弈问题，足够聪明，可以构造出让下一步的人输的情况
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
//当然，这道题可以分析成 偶数先手必赢，奇数先手必输
     //return !(N&1);