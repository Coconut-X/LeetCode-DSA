class Solution {
public:
    string removeStars(string s) {
    
    stack<char> s1;
    string rev="";

    for(int i=0;i<s.size();i++)
        s1.push(s[i]);
    
    int star=0;
    while(!s1.empty())
    {
        while(s1.top()=='*')
        {
            star++;
            s1.pop();
        }

        while(star!=0 and s1.top()!='*')
        {
            s1.pop();
            star--;
        }

        if(!s1.empty() and s1.top()!='*')
        {
            rev+=s1.top();
            s1.pop();
        }
        
    }

    reverse(rev.begin(), rev.end());

    return rev;

    }
};