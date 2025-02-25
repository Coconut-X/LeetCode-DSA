class Solution {
public:
    int minLength(string s) {

        stack<char> stek;

        if (s.empty()) {
            return 0;
        }
        
        stek.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            char c=s[i];

            if(!stek.empty() and 
            ((stek.top()=='A' and c=='B') or  (stek.top()=='C' and c=='D')))
            {
                stek.pop();
            }
            else
            {
                stek.push(c);
            }   
        }

        return stek.size();
    }
};