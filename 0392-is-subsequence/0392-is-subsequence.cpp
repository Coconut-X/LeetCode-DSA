class Solution {
public:
    bool isSubsequence(string s, string t) {

        int s1=t.size(), s2=s.size();
        if(s2>s1) return false;
        if(s==t) return true;
        
        int j=0;
        
        for(int i=0;i<s1;i++)
        {
            if(t[i]==s[j])
            {
                j++;
            }
            if(j==s2) return true;
        }
        return false;
    }
};