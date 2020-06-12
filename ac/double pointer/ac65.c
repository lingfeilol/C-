class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3) return ret;
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int x=nums[i],tmp=0-x,begin=i+1,end=nums.size()-1; //转换成两数之和的问题
            while(begin<end)
            {
                int y=nums[begin],z=nums[end];
                if(y+z<tmp) begin++;
                else if(y+z>tmp) end--;
                else 
                {
                    ans.insert({x,y,z});
                    begin++,end--;
                }
            }
        }
        for(auto e:ans)
        {
            ret.push_back(e);
        }
        return ret;
    }
};