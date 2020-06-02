class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> dq;//保存最大值的下标，根据下标就好判断队头是否是要滑出
        for(int i=0;i<nums.size();i++)
        {
            if(dq.empty())
                dq.push_back(i);
            else
            {
                if(dq.front()<=i-k) //滑出
                    dq.pop_front();
                while(!dq.empty()&& nums[dq.back()]<nums[i])//队列里维持单调递减
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            if(i>=k-1)
                ret.push_back(nums[dq.front()]);
        }
        return ret;
    }
};