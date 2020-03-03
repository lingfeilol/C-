class Solution {
public:
    int firstUniqChar(string s) {
        int count[256]={0};
        int size=s.size();
        for(int i=0;i<size;i++)
        {
            count[s[i]]++;//统计每个字符出现的次数
        }
        //找到第一个只出现一次的字符
        for(int i=0;i<size;i++)
        {
            if(count[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};