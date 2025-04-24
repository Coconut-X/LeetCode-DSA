class Solution {
public:

    int func(string &s)
    {
        int m =-1;
        vector<int> lps(s.size());

        int len =0;
        lps[0] = 0;

        for(int i=1;i<s.size();)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                m = max(m,len);
                i++;
            }
            else
            {
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else if(len!=0)
                {
                    len = lps[len-1];
                }
            }
        }
        return lps.back();
    }
    

    string longestPrefix(string s) {

        int pos = func(s);
        if(pos ==0) return "";
        cout<<pos;
        string p = s.substr(0,pos);
        if(p == s.substr(s.size()-pos, s.size()))
            return s.substr(0,pos);
        return "";

       
    }
};