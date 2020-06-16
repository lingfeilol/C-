class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        int r = arr.back();
        int ans = 0, diff = target;//差值
        for (int i = 1; i <= r; ++i) {//枚举每一个数
            auto iter = lower_bound(arr.begin(), arr.end(), i);//找到最右边的
            int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * i;//计算此时的数组和
            if (abs(cur - target) < diff) {//找差值最小的
                ans = i;
                diff = abs(cur - target);
            }
        }
        return ans;
    }
};