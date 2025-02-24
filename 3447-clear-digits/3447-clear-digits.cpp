class Solution {
public:
    string clearDigits(string s) {

        stack<char> s1, s2;
        int count=0;

        for(int i=0;i<s.size();i++)
        {
           
            if(s[i]>='0' and s[i]<='9')
            {
                if(count!=0)
                {
                    s1.pop();
                    count--;
                }
            }
            else
            {
                s1.push(s[i]);
                count++;
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