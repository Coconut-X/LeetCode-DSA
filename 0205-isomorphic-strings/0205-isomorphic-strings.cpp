class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size()!=t.size()) return false;

        unordered_map<char,char> mep;
        unordered_map<char, bool> done;

        for(int i=0;i<s.size();i++)
        {
            if(!mep[s[i]] and !done[t[i]])
            {
                mep[s[i]]=t[i];
                done[t[i]]=true;
                continue;
            }

            if(mep[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};