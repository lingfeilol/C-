class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.empty()&&arr.empty()) return true;

        if(target.empty()||arr.empty()) return false;
        vector<int> map1(1001,0);
        for(auto t:target)
        {
            map1[t]++;
        }
        for(auto a:arr)
        {
            map1[a]--;
        }
        for(int i=0;i<map1.size();i++)
        {
            if(map1[i]!=0)
                return false;
        }
        return true;
    }
};