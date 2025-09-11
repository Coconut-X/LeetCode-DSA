class Solution {
public:
    inline bool v(char &c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {
        // string t = "";
        vector<int> freq(123,0);
        int n = s.size();

        for(int i  = 0; i < n; i++){
            if(v(s[i])) freq[s[i]]++;
        }

        // sort(t.begin(),t.end());
        
        for(int i = 0, j = 65; i < n; i++){
            if(v(s[i])){
                while(freq[j]==0 and j <= 122){
                    j++;
                }
                if(j<=122 and freq[j]!=0){
                    s[i] = j;
                    freq[j]--;
                }
            }
        }

        return s;
        
    }
};