class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, bool> r1;
        unordered_map<char, bool> r2;
        unordered_map<char, bool> r3;

        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(char c:s1) r1[c] = true;
        for(char c:s2) r2[c] = true;
        for(char c:s3) r3[c] = true;
        vector<string> output;
        for(auto &word: words){
            if(word.size() == 1) output.push_back(word);
            else{
                char c = tolower(word[0]);
                int in = r1[c] ? 1 : r2[c] ? 2 : 3;
                bool miss = false;
                for(int i = 1; i < word.size(); i++){
                    int cur = r1[tolower(word[i])] ? 1 : r2[tolower(word[i])] ? 2 : 3;
                    if(in != cur){
                        miss = true;
                        break;
                    }
                }
                if(!miss) output.push_back(word);
            }
        }
        return output;
    }
};