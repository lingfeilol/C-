class Solution {
    pair<int,int>p;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            if(!map.count(nums[i]))
                map[nums[i]]=i;
            else
            {
                if(i-map[nums[i]]<=k)
                    return true;
                map[nums[i]]=i;//没有返回的话，就更新一下此相同值的下标
            } 
        }
        return false;
    }
};