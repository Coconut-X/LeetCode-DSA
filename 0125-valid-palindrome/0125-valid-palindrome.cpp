class Solution {
public:
    bool isPalindrome(string s) {
        for(auto& x: s) x=tolower(x);

        int i=0, j=s.size()-1;

        auto valid=[](char c){
            return (c>=65 and c<=90) or (c>=97 and c<=122) or (c-'0'>=0 and c-'0'<=9);
        };

        

        while(i<j)
        {
            while(i<j and !valid(s[i])) i++;
            while(i<j and !valid(s[j])) j--;
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
        
    }
};