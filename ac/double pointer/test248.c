class Solution {
public:
    string reformat(string s) {
        string digits;
        string letters;
        string ret;
        for(auto e: s)
        {
            if('0'<=e && e<='9')
                digits.push_back(e);
            else
                letters.push_back(e);
        }
        int dlen=digits.size();
        int llen=letters.size();
        if(abs(dlen-llen)>1)
            return ret;
        int i=0,j=0;
        if(dlen<llen)
            digits.swap(letters);
        while(i<digits.size()&& j<letters.size())
        {
            ret.push_back(digits[i++]);
            ret.push_back(letters[j++]);
        }
        if(i<digits.size())
            ret.push_back(digits[i]);
        return ret;
    }
};