class Solution {
public:
    vector<vector<string>> ret;

    bool ishuiwen(string &s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        if(s.empty()) return ret;
        vector<string> tmp;
        backtravel(s,tmp,0);
        return ret;
    }
    void backtravel(string &s,vector<string>& tmp,int index)
    {
        if(index == s.size())
        {
            ret.push_back(tmp);
            return ;
        }
        for(int i=index; i<s.size();i++)
        {
            string sub=s.substr(index,i-index+1);
            if(ishuiwen(sub))
            {
                tmp.push_back(sub);
                backtravel(s,tmp,i+1);
                tmp.pop_back();
            }
        }
    }
};