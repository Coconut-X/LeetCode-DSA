class Solution {
public:
    string makeGood(string s) {

    stack<char> stek;
    for(int i=0;i<s.size();i++)
    {
        if(!stek.empty() and abs(stek.top()-s[i])==32)
        {
            stek.pop();
        }
        else{
            stek.push(s[i]);
        }
    }

    string t="";
    while(!stek.empty()){
        t+=stek.top();
        stek.pop();
    }
    reverse(t.begin(), t.end());
    return t;

        
    }
};