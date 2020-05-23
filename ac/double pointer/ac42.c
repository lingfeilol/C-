class Solution {
public:
    string minWindow(string s, string t) {
        int slen=s.size(),tlen=t.size();
        int as[128]={0};
        int ts[128]={0};
        int distance=0;
        int minlen=slen+1,index=0;//记录最小长度，配和下标，输出子串
        for(auto e:t)
        {
            ts[e]++;
        }
        int left=0,right=0;
        while(right<slen)
        {
            //右边界
            if(ts[s[right]]==0)//不是目标串里的字符，继续找
            {
                right++;
                continue;
            }
            //是目标串里的字符了，就计数
            if(as[s[right]]<ts[s[right]])//窗口串里的 目标串的字符的个数必须要大于等于才行
            {
                distance++;//窗口里与目标串里匹配的字符个数，只要满足小于就代表找到一个有效的，多了的也无意义了，够了就行
            }
            as[s[right]]++;//判断完，在更新计数
            right++;
            while(distance==tlen)//说明窗口串里包含目标串里的所有字符，更新左边界，找最小子串
            {
                if(right-left<minlen)//只要是还能在这个循环里的，说明还都是符合条件的，更新最小长度
                {
                    minlen=right-left;
                    index=left;
                }
                //左边界移动
                if(ts[s[left]]==0)
                {
                    left++;
                    continue;
                }
                if(as[s[left]]==ts[s[left]])//本来在窗口串里都是大于等于的，遇到等于了，随后都是要缩边界的
                {
                    distance--;
                }
                as[s[left]]--;
                left++;
            }
        }
        return minlen==slen+1? "":s.substr(index,minlen);
    }
};