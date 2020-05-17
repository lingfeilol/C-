class Solution {
    vector<pair<string,int>> sv;
public:
    string arrangeWords(string text) {
        int len=text.size();
        text[0]+='a'-'A'; //首字母先大写转小写
        //先把句子分割成单词，存到数组中排序
        int start=0;
        for(int i=0;i<=len;i++)
        {
            if(i==len || text[i]==' ')//遇到空格，或者走到尾了,注意substr的关系，所以要判断到最后一位后面
            {
                sv.push_back(make_pair(text.substr(start,i-start) ,sv.size()));
                start=i+1;
            }
        }
        //在根据 单词长度和出现的优先级 从小到大排序 ;加上优先级的原因就是sort不是稳定排序
        sort(sv.begin(),sv.end(),[](const auto& a,const auto& b){
            return a.first.size()==b.first.size()? a.second<b.second:a.first.size()                        <b.first.size(); });
        //排好序之后再放在一个输出字符串中去
        string ret;
        for(int i=0;i<sv.size();i++)
        {
            ret+=sv[i].first;
            ret+=' ';
        }
        ret.resize(len);
        ret[0]+='A'-'a';
        return ret;
    }
};