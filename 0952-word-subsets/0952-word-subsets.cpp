class myMap {
public:
    unordered_map<char, int> h;
};

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
      
        unordered_map<char, int> maxFreq;
        for (auto& word : words2) 
        {
            unordered_map<char, int> tempFreq;
            for (char c : word) {
                tempFreq[c]++;
                maxFreq[c] = max(maxFreq[c], tempFreq[c]);
            }
        }

        vector<string> result;
        for (auto& word : words1) 
        {
            unordered_map<char, int> wordFreq;
            for (char c : word) {
                wordFreq[c]++;
            }

            bool isUniversal = true;
            for (auto& [key, value] : maxFreq) {
                if (wordFreq[key] < value) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
