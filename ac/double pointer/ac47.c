class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen=s.size(),plen=p.size();
        int left=0,right=0;
        unordered_map<char, int> needs, windows;
        vector<int> ret;
        int distance=0;//记录出现同一字符的个数
        for(auto e:p)
        {
            needs[e]++;
        }
        while(right<slen)
        {
            char c=s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if(needs.count(c))
            {
                windows[c]++;
                if(windows[c]==needs[c])
                    distance++;
            }
            while(right-left>=plen)
            {
                // 当窗口符合条件时，把起始索引加入 res
                if(distance==needs.size())
                    ret.push_back(left);
                char d=s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if(needs.count(d))
                {
                    if(windows[d]==needs[d])
                    {
                        distance--;
                    }
                    windows[d]--;
                }
            }
        }
        return ret;
    }
};