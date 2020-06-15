class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if(strs.empty())  return "";
            //纵向扫描
            for(int i=0;;i++)
            {
                for(auto & word:strs)
                {
                    if(i==word.size()|| word[i]!=(*strs.begin())[i])
                        return word.substr(0,i);
                }
            }
            return "";

        // //纵向扫描
        // string ret;
        // if(strs.empty()) return ret;
        // for(int j=0;j<strs[0].size();j++)//从第一列开始 
        // {
        //     for(int i=1;i<strs.size();i++)//从第二行开始，与第一行的即第一个字符串每个字符对比
        //     {
        //         if(strs[0][j]!=strs[i][j]|| j==strs[i].size()) //不匹配或者当前列数超过此串长度
        //             return ret;//不匹配则直接返回
        //     }
        //     ret+=strs[0][j];//当前列匹配，则记录
        // }
        // return ret;
    }
};