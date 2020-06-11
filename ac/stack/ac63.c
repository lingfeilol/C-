class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ret(T.size());
        stack<int> st;
        for(int i=0;i<T.size();i++)
        {
            while(!st.empty()&& T[i]>T[st.top()])
            {
                ret[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};