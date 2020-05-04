class Solution {
public:
    int jump(vector<int>& nums) {
        int end=nums.size()-1;
        int ans=0;
        int i=0;
        int index=0;
        while(i<end)
        {
            int max=0;
            int r=i+nums[i];//可以到达的右边界
            if(r>=end)//可以一次到达重点了的
            {
                ans++;
                break;
            }
            int j=i;
            for(;j<=r;j++)  //贪心选择   注意贪心是贪心的下一步的最远位置，而能跳到的最远位置由下标位置和能跳多远决定的
            {
                if(nums[j]+j>=max)
                {
                    max=nums[j]+j;
                    index=j;
                }
            }
            i=index;
            ans++;
        }
        return ans;

        
    }
};