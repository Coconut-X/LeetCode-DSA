class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<int,int> sum;

        auto vowel=[](char c){
            return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
        };

        for(int i=0;i<s.size();i++)
            sum[i]=((i==0? vowel(s[i]): sum[i-1] + vowel(s[i])));

        int m=0;

        for(int i=0;i+k-1< s.size();i++)
            m=max(sum[i+k-1]-sum[i-1],m);

        return m;
    }
};