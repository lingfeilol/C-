class Solution {
    //是否包含所有，可以在串中滑动长度为k的子串，放入set中，只要最后个数也满足2^k个，便是全部包含
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> set;
        int tmp=0;
        for(int i=0;i<s.size();i++)
        {
            tmp=tmp*2+s[i]-'0';//因为是01串，且也可以用整数代替
            if(i>=k) tmp-=(s[i-k]-'0')<<k;//维持一个长度为k
            if(i>=k-1) set.insert(tmp);
        }
        return set.size()== (1<<k);
    }
};