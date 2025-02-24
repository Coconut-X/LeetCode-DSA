class Solution {
public:
    string clearDigits(string s) {

        stack<char> s1;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' and s[i]<='9')
            {
                if(s1.size())
                {
                    s1.pop();
                }
            }
            else
            {
                s1.push(s[i]);
            }
        }

        string res="";
        while(!s1.empty())
        {
            res+=s1.top();
            s1.pop();
        }

        reverse(res.begin(), res.end());

        return res; 
        
    }
};