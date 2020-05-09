class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int dist=0;//定义一个距离，每次取最远能跳到距离，最后看是否超出或等于最后一个位置
        for(int i=0;i<n&& i<=dist;i++)//必须还要满足i<dist,不然说明最远距离小于当前位置，那就跳不过去的
        {
            dist=max(dist,nums[i]+i);
        }
        return dist>=n-1;
    }
};