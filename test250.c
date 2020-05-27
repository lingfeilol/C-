class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int,int> map{{0,1}};
        int ret=0;
        int sum=0;
        for(int e:A)
        {
            sum+=e;
            int tmpmod=(sum%k+k)%k;
            if(map.count(tmpmod))//同余定理
                ret+=map[tmpmod];
            map[tmpmod]++;
        }
        return ret;
    }
};