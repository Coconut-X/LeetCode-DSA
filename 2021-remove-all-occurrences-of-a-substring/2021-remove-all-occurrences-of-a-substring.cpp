class Solution {
public:



    string removeOccurrences(string s, string part) {

        if(part.size()>s.size()) return s;
        
        int pos=s.find(part);

        while(pos!=string::npos)
        {
            s=s.substr(0,pos)+s.substr(pos+part.size());
            pos=s.find(part);
        }

        return s;
    }
};