class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> visited(nums.size());
        dfs(res, temp, nums, 0);
        return res;
    }
private:
    set<vector<int>> ss;//去重
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int start) {
        if (temp.size() >= 2) {
            if (!ss.count(temp)) {
                res.push_back(temp);
                ss.insert(temp);
            }
        }
        for (int i = start; i < nums.size(); i++) {
            if (temp.empty() || nums[i] >= temp.back()) {
                temp.push_back(nums[i]);
                dfs(res, temp, nums, i + 1);
                temp.pop_back();
            }
        }
    }
};