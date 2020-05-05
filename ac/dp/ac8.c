class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        int ans=1;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i=0;i<len;i++)//base case 区间里只有一个数，即长度为一
        {
            dp[i][i]=1;
        }
        //倒着遍历   因为状态转移方程的原因，必须要先知道前面三种情况的状态，所以行倒着遍历
        for(int i=len-1;i>=0;i--)
        {
            for(int j=i+1;j<len;j++)
            {
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
};
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        int ans=1;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i=0;i<len;i++)//base case 区间里只有一个数，即长度为一
        {
            dp[i][i]=1;
        }
        //斜着遍历 
        for(int q=2;q<=len;q++)//区间长度
        {
            for(int i=0;i<len-q+1;i++)//头
            {
                int j=i+q-1;//尾
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
};