class Solution {
public:
//问题转化为 A[i]+i + A[j]-[j],且由于i < j,所以每次遍历j时就可以把之前的A[i]+i最大值保留下来 
    int maxScoreSightseeingPair(vector<int>& A) {
        int ret=INT_MIN;
        int pre=A[0]+0;
        for(int j=1;j<A.size();j++)
        {
            ret=max(ret,A[j]-j+pre);//跟新答案
            pre=max(pre,A[j]+j);//存之前的最大值
        }
        return ret;
    }
};