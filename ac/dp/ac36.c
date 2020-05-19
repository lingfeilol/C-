class Solution {
public:
    int numDecodings(string s) {
        int size=s.size();
        if(s[0]=='0') return 0;//无法编码
        vector<int> dp(size+1,0);//表示几位数的编码总数
        dp[0]=1;//空字符的编码方式
        //当前位的编码  i-1  i当前位数  i+1
        dp[1]=1;//一个字符的编码
        for(int i=1;i<size;i++)
        {
           if(s[i]=='0')//有无法编译的情况，因为能编译的区间位【1~26】
           {
               if(s[i-1]=='1'|| s[i-1]=='2')//可以当个位
                    dp[i+1]=dp[i-1];//占两位，必须是组合编码
                else
                    return 0; //无法编译
            }
            else
            {
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))//s[i-1]s[i]两位数要小于26的情况
                    dp[i+1] = dp[i]+dp[i-1];
                else//其他情况
                    dp[i+1] = dp[i];
            } 
            //只用考虑'1'和'2'的情况，因为只有这两种可以和后一位有合并编码的情况
            //其他的情况就不需要在考虑了,dp[i]=dp[i-1];
        }
        return dp[size];
    }
};