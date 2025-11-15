class Solution {
public:

    pair<int,int> makepal(const string &s, int index){
        int l = index, r = index;
        while (l - 1 >= 0 && r + 1 < (int)s.size() && s[l-1] == s[r+1]) {
            l--, r++;
        }
        return {l, r};
    }

    pair<int,int> makeevenpal(const string &s, int l, int r){
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            l--, r++;
        }
        return {l+1, r-1};
    }

    string longestPalindrome(string s) {

        int bestL = 0, bestR = 0, bestLen = 1;

        for(int i = 0; i < (int)s.size(); i++){

            auto p1 = makepal(s, i);
            int len1 = p1.second - p1.first + 1;
            if(len1 > bestLen){
                bestLen = len1, bestL = p1.first, bestR = p1.second;
            }

            if(i + 1 < (int)s.size() && s[i] == s[i+1]){
                auto p2 = makeevenpal(s, i, i+1);
                int len2 = p2.second - p2.first + 1;
                if(len2 > bestLen){
                    bestLen = len2, bestL = p2.first, bestR = p2.second;
                }
            }
        }

        return s.substr(bestL, bestLen);
    }
};
