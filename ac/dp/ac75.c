class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        //dp[i]取决于 0~i中，两端，前一段 满足dp[j]=true.后一段是在字典中存在的，则说明dp[i]=true
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i;j>=0;j--)//枚举这个区间里的每一段，且只要判断满足了，后面就可以不用在考虑了
            {
                string word=s.substr(j,i-j);
                if(st.find(word)!=st.end() && dp[j])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};