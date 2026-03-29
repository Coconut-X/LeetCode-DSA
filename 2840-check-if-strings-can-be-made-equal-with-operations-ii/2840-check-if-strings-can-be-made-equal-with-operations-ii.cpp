class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> o1;
        unordered_map<char, int> e1;
        unordered_map<char, int> o2;
        unordered_map<char, int> e2;
        int n = s1.size();
        for(int i = 0 ; i < n; i++){
            if(i%2){
                o1[s1[i]]++;
                o2[s2[i]]++;
            }
            else{
                e1[s1[i]]++;
                e2[s2[i]]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(i%2){
                if(o1[s1[i]]!=o2[s1[i]]) return false;
            }
            else{
                if(e1[s1[i]]!=e2[s1[i]]) return false;
            }
        }
        return true;
    }
};