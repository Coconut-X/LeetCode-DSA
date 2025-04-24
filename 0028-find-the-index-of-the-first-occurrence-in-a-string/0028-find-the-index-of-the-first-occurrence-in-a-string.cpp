class Solution {
public:

    vector<int> func(string &s)
    {
        vector<int> lps(s.size(),0);
        int len = 0;
        lps[0] = 0;
        for(int i=1;i<s.size();)
        {
            if(s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i] = 0;
                    i++;
                }
                else if(len!=0) 
                {
                    len = lps[len -1];
                }
            }
        }
        return lps;
    }

    int kmp(string &s, string &p)
    {
        vector<int> lps = func(p);

        int i = 0, j = 0;

        while(i<s.size())
        {
            if(s[i] == p[j])
            {
                i++, j++;

                if(j==p.size())
                {
                    return i-j;
                }
            }
            else 
            {
                if(j==0) i++;
                else if(j>0) j = lps[j-1];
            }
        }   
        return -1;
    }


    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
};