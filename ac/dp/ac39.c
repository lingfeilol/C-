class Solution {
    //用二进制来保存元音字母出现的奇偶性 ，
    //aeiou对应 00000 说明未出现偶数，00101说明i和u出现奇数次
    //再根据奇数-奇数=奇数，偶数-偶数=偶数，奇数-偶数=奇数
    //可以把问题转换成前缀和的问题，当区间【i，j】元音出现次数为偶数时，意味着【0，j】【i-1，j】两区间内元音出现次数也都是偶数，此时在计算下标差，便是满足条件的长度，找最大值
public:
    int findTheLongestSubstring(string s) {
        vector<int> pos(32,-1);//五个元音字母，用二级制表示，最多只有2^5-1种情况
        //数组存储状态，下标为索引
        pos[0]=0;
        int status=0,ret=0;
        for(int i=0;i<s.size();i++)//记录每个下标对应的状态
        {
            if(s[i]=='a') status^=(1<<0);
            else if(s[i]=='e') status^=(1<<1);
            else if(s[i]=='i') status^=(1<<2);
            else if(s[i]=='o') status^=(1<<3);
            else if(s[i]=='u') status^=(1<<4);

            if(pos[status]!=-1)//判断一下之前此状态码有没有出现过，出现过，那这时区间内便是满足条件
            {
                ret=max(ret,i+1-pos[status]);//求出最长的子长度
            }
            else//没出现过，更新此状态码和下标
            {
                pos[status]=i+1;
            }
        }
        return ret;
    }
};