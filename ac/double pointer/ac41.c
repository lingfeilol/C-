class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret=0;
        bool flag[256]={false};//记录字符是否出现过 ，维护一个不包含重复字符的子数组
        for(int i=0,j=0;i<s.size();i++)
        {
            while(j<s.size()&& flag[s[j]]==false)//j先去找到重复的那个字符，然后停下，更新i
            {
                flag[s[j]]=true;
                j++;
            }
            flag[s[i]]=false;//i收缩区间同时，记录区间长度
            ret=max(ret,j-i);
        }
        return ret;
    }
};