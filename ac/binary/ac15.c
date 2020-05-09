class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x;
        int ans=-1;
        while(left<=right)//范围一直在缩小，且会朝着答案出现的范围缩小，所以一定会跳出，要么是前一个，要么就是当前值
        {
            int mid=(left+right)/2;
            if((long long)mid*mid<=x)
            {
                ans=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        return ans;
    }
};