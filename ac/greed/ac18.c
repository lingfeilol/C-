class Solution {
public:
//想要分发的多，那就要尽可能的先给胃口小的孩子分配饼干，即贪心
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int i=0;
        int j=0;
        // for( i=0;i<g.size();i++)
        // {
        //    while(j<s.size()&& g[i]>s[j]) j++;//不满足胃口，就往后找可以满足的
        //    if(j<s.size())//满足的下标还是在区间里，即合法
        //    {
        //        ans++;
        //        j++;
        //    }
        // }
        // return ans;
        while(i<g.size()&& j<s.size())
        {
            if(g[i]<=s[j])//满足条件
                i++;//满足当前孩子，遍历下一个孩子
            j++;//满足就往后试下一个饼干和下一个孩子，不满足就要试下一个饼干和刚才的孩子
        }
        return i;
    }
};