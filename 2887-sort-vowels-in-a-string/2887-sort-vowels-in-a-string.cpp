class Solution {
public:
    inline bool v(char &c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {

        int n = s.size();
        vector<int> buckets(10,0);
        vector<char> vowels = {'A','E','I','O','U','a','e','i','o','u'};

        unordered_map<int,int> mep;
        mep['A'] = 0, mep['E'] = 1, mep['I'] = 2, mep['O'] = 3, mep['U'] = 4, mep['a'] = 5, mep['e'] = 6, mep['i'] = 7, mep['o'] = 8, mep['u'] = 9;

        for(int i  = 0; i < n; i++){
            if(v(s[i])) buckets[mep[s[i]]]++;
        }
        
        for(int i = 0, j = 0; i < n and j<=9; i++){
            if(v(s[i])){
                while(buckets[j]==0 and j<=9){
                    j++;
                }
                if(j<=9 and buckets[j]!=0){
                    s[i] = vowels[j];
                    cout<<i<<" "<<j<<endl;
                    buckets[j]--;
                }
            }
        }

        return s;
        
    }
};