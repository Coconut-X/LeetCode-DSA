class Solution {
public:
    int maxDepth(string s) {

        stack<char> stek;

        int m=0;
        int cur=0;

        for(auto c: s)
        {
            if(c=='(')
            {
                cur++;
                m=max(m,cur);
            }
            else if(c==')')
            {
                cur--;   
            }
        }

        return m;
    }
};