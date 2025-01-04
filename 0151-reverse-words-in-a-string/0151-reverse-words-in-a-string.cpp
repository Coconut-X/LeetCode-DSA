class Solution {
public:
    string reverseWords(string s) {

        int n=s.size();

        vector<string> r;
        string t="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ') t+=s[i];
            if((s[i]==' ' or i==n-1 ) and t.size())
            {
                r.push_back(t);
                t="";
                continue;
            }
        }

        string ans="";

        reverse(r.begin(), r.end());
                              
        for(int i=0;i<r.size();i++)
        {
            ans+=r[i];
            if(i!=r.size()-1) ans+=" ";
        }

        return ans;
        
    }
};