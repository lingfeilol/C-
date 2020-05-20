class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int len=S.size();
        vector<int> dp(len,0);
        //dp[i]定义为【0~i】范围内满足条件最少的翻转次数
        //对于当前位 为1的时候，可以选择把前面的1全部变成0，因为1是排在右边的，且是从前往后找，所以可以也考虑先不管 
        //对越当前位 为0的时候，可以选择把前面的1全部变成0，也可以选择把0变成1 ，取最小值即最优

        int onecount=0;//记录当前位置之前的1的个数
        for(int i=0;i<len;i++)
        {
            if(S[i]=='1')
            {
                onecount++;
                dp[i]=(i==0)? 0:min(dp[i-1],onecount);//也可以0:dp[i-1]
            }
            else
            {
                dp[i]=(i==0)?0: min(dp[i-1]+1,onecount);
                //dp[i-1]+1为0的个数  onecount为1的个数
            }
        }
        return dp[len-1];
    }
};