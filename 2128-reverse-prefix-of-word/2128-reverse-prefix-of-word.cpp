class Solution {
public:
    string reversePrefix(string word, char ch) {

        stack<char> stek;
        int i=0;
        bool found=false;
        for(;i<word.size();i++)
        {
            stek.push(word[i]);

            if(word[i]==ch)
            {
                found=true;
                break;
            }
        }
        if(!found) return word;
        string t="";
        while(!stek.empty())
        {
            t+=stek.top();
            stek.pop();
        }

        for( int j=i+1;j<word.size();j++)
        {
            t+=word[j];
        }

        return t;

        
    }
};