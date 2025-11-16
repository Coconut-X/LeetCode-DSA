class Solution {
public:
    int numSub(string s) {

        int i = 0;
        int count = 0;
        while(i < s.size()){
            while(i < s.size() and s[i]=='0') i++;
            if(i==s.size()) break;
            int one = 0;
            while(i < s.size() and s[i]=='1') i++, one = (one + 1)%(1000000007);
            long long tmp = (1LL * one * (one + 1) / 2) % 1000000007;
            count = (count + tmp) % 1000000007;

        }
        return count;
    }
};