//利用字典树
class Tiretree
{
public:
        bool isend;
        Tiretree* next[26]={nullptr};//指针数组，映射26个字母

        Tiretree()
            :isend(false)
        {}
    

    void insert(string word)//往字典树里插入字符串
    {
        auto cur=this;
        for(int i=word.size()-1;i>=0;i--) //注意，此题这里是需要反向插入的
        {
            if(cur->next[word[i]-'a']==nullptr)
            {
                cur->next[word[i]-'a']=new Tiretree();
            }
            cur=cur->next[word[i]-'a'];
        }
        cur->isend=true;//单词结尾
    }

    bool search(string word)//搜索单词
    {
        auto cur=this;
        for(auto w:word)
        {
            cur=cur->next[w-'a'];
            if(cur==nullptr)
                return false;
        }
        return cur->isend;//是否走到最后
    }
    
    bool startwith(string word)//前缀匹配
    {
        auto cur=this;
        for(auto w:word)
        {
            cur=cur->next[w-'a'];
            if(cur==nullptr)
                return false; //一旦不匹配，那就说明不是
        }
        return true;//只要这个word被匹配完了，就说明是前缀了
    }

};
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(),dictionary.end());
        int n=sentence.size();
        vector<int> dp(n+1);
    //1.普通匹配 超时
    //    for(int i=1;i<=n;i++)
    //     {
    //         dp[i]=dp[i-1]+1;//要么没匹配，则未匹配长度加一
    //         for(int begin=0;begin<i;begin++)//以i为尾字符，判断是否在字典里 //此判断方法会超时
    //         {
    //             if(st.count(sentence.substr(begin,i-begin)))
    //             {
    //                 dp[i]=min(dp[i],dp[begin]); //要么匹配，为以begin为尾的未匹配字符串长度与未匹配的最小值
    //             }
    //         }
    //     }
    //     return dp[n];
    // }

    //2.利用固定的单词长度来判断匹配 ，可通过
    // for(int i=1;i<=n;i++)
    // {
    //     dp[i]=dp[i-1]+1;
    //     for(auto &word :dictionary)
    //     {
    //         int len=word.size();
    //         if(i>=len && word==sentence.substr(i-len,len))//判断字典里的每一个单词 //可以ac
    //         {
    //             dp[i]=min(dp[i],dp[i-len]);
    //         }
    //     }
    // }
    // return dp[n];
    // }

    //3.利用字典树（前缀树）匹配单词，来判断是否匹配
    //把字典中的字符串插入到前缀树中，方便匹配
    Tiretree* root=new Tiretree();
    for(auto &word:dictionary)
    {
        root->insert(word);
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+1;
        Tiretree* cur=root;
        for(int j=i;j>=1;j--) //从尾到头匹配，配和字典树从尾开始插入，只要不是相同的尾，那就没必要继续下去，可以减少
        {
            int index=sentence[j-1]-'a';
            if(cur->next[index]==nullptr)
            {
                break; //尾部字符不同，则不存在匹配，直接跳出
            }
            else if(cur->next[index]->isend) //存在匹配且匹配完成
            {
                dp[i]=min(dp[i],dp[j-1]);//此时j为匹配单词的最后一个单词
            }
            cur=cur->next[index];//迭代匹配
        }
    }
    return dp[n];
    }
};