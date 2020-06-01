class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3) return false;
        vector<int> vmin(nums.size()+1);//从0~当前位置的最小值 ，作为i来看
        vmin[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            vmin[i]=min(vmin[i-1],nums[i]);
        }
        stack<int> st;
        for(int j=nums.size()-1;j>=0;j--)//nums[j]作为【k】 ,栈里的元素作为【j】老看
        {
            if(nums[j]>vmin[j])
            {
                while(!st.empty()&& st.top()<=vmin[j])//存的是【j】的最小值，但是大于【i】的
                {
                    st.pop();
                }
                if(!st.empty()&& st.top()<nums[j])
                    return true;
                st.push(nums[j]);
            }
        }
        return false;

    }
};