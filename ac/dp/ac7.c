class Solution {
public:
//dp[i][j]状态表示为i~j区间是否回文子串    
//而区间长度由s字符串长度决定 从1 2 3一直到 len的区间长度
//dp状态初始状态有两种，就是区间长度为1 即dp[i][i]     和区间长度为2 即dp[i][i+1]
//后面其他状态可以有 这两种状态 向前取一位向后取一位判断是否相同，来进一步判断是否为回文子串
    string longestPalindrome(string s) {
        int len=s.size();
        int max=1;//保存最长回文串长度
        int k=0;//保留当前回文串的其实位置，配和区间（串长）得到结果串
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        //base case
        for(int i=0;i<len;i++)
        {
            dp[i][i]=true; 
            max=1;
            k=i;         
        }
        for(int i=0;i<len-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                max=2;
                k=i;
            }
                
        }
        for(int q=3;q<=len;q++)//区间长度
        {
            for(int start=0;start<len-q+1;start++)//头
            {
                int end=start+q-1;//尾
                if(s[start]==s[end]&& dp[start+1][end-1])
                {
                    dp[start][end]=true;
                    max=q;
                    k=start;
                }
            }
        }
        return s.substr(k,max);
        
    }
};