class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s2len=s2.size(),s1len=s1.size();
        int left=0,right=0;
        int distance=0;
        unordered_map<char,int>window,need;
        for(auto e:s1)
        {
            need[e]++;
        }
        while(right<s2len)
        {
            char c=s2[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c]==need[c])
                    distance++;
            }
            while(right-left>=s1.size())//控制区间长度
            {
                char d=s2[left];
                left++;
                if(distance==need.size())
                    return true;
                if(need.count(d))
                {
                    if(window[d]==need[d])
                        distance--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};