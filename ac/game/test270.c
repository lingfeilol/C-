class Solution {
public:
    string reformatDate(string date) {
        string ret;
        vector<string> vs={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        stringstream ss(date);
        string word;
        int year,month,day=0;
        int k=0;
        while(ss>>word)
        {
            int count=0;
            for(int i=0;i<word.size();i++)
            {
                if('0'<=word[i]&& word[i]<='9')
                {
                    count=count*10+word[i]-'0';
                }
            }
            if(count==0)
            {
                for(int i=0;i<12;i++)
                {
                    if(vs[i]==word)
                    {
                        month=i+1;
                    }
                }
            }
            else if(count<32)
            {
                day=count;
            }
            else 
            {
                year=count;
            }    
        }
        ret+=to_string(year)+'-';
        if(month<=9)
        {
            ret+='0';
        }
        ret+=to_string(month)+'-';
        if(day<=9)
            ret+='0';
        ret+=to_string(day);
        return ret;
    }
};