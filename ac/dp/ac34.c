class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0]=0;
        for(int i=1;i<=num;i++)
        {
            dp[i]=(i&1) +dp[i>>1];  //可以根据最后一个比特位和前面算出来的状态来求
            //比如 5 101  可以根据最后一位1 和 dp['10']即dp[i>>1] 得出
        }
        return dp;
    }
};