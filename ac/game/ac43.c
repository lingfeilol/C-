class Solution {
public:
    int maxVowels(string s, int k) {
        int len=s.size();
        int ret=0;
        int count=0;
        vector<int> num(s.size()+1,0);
        for(int i=1;i<=s.size();i++)
        {
            if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u')
                num[i]=num[i-1]+1;
            else
                num[i]=num[i-1];
        }
        for(int i=0,j=0;i<len-k+1;i++)
        {
            j=i+k;
            ret=max(ret,num[j]-num[i]);
        }
        return ret;
    }
 
};