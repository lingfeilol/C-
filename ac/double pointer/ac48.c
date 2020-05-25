class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.empty()|| s.empty()) return ret;
        int slen=s.size(), wlen=words.size(), m=words[0].size();
        unordered_map<string,int> window,need;
        for(auto e:words)
        {
            need[e]++;
        }
        for(int i=0;i<=slen-wlen*m;i++)//逐位判断，在规定长度内是否符合条件
        {
            int distance=0;
            for(int j=0;j<wlen;j++)
            {
                string tmp=s.substr(i+j*m,m);
                if(need.count(tmp))
                {
                    window[tmp]++;
                    if(window[tmp]==need[tmp])
                        distance++;
                } 
            }
            if(distance==need.size())
                ret.push_back(i);
            window.clear();  
        }
        return ret;
    }
};