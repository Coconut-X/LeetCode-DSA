class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool> mep;
        for(auto &b: brokenLetters){
            mep[b] = true;
        }

        stringstream ss(text);
        vector<string> words;
        string read;
        while(getline(ss, read, ' ')){
            words.push_back(read);
        }
        int count = 0;
        for(auto &w: words){
            bool canType = true;
            for(int i = 0; i < w.size(); i++){
                if(mep[w[i]]){
                    canType = false;
                    break;
                }
            }
            count+=canType;
        }
        return count;
    }
};