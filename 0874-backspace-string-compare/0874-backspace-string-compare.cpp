class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stek1,stek2;
        string s1="", s2="";

        for(auto c: s){
            if(c=='#'){
                if(stek1.empty()){
                    continue;
                }
                stek1.pop();
                continue;
            }
            stek1.push(c);
            
        }

        
        for(auto c: t){
            if(c=='#'){
                if(stek2.empty()){
                    continue;
                }
                stek2.pop();
                continue;
            }
            stek2.push(c);
        }

        if(stek1.size()!=stek2.size()) return false;

        while(stek1.size())
        {
            char c = stek1.top();
            s1+=c;
            c = stek2.top();
            s2+=c;
            stek1.pop(), stek2.pop();
        }

        return s1==s2;
        
    }
};