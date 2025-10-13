class Solution {
public:
    bool isanagram(string& a, string& b) {
        if (a.size() != b.size()) return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < a.size(); i++) {
            freq[a[i] - 'a']++;
            freq[b[i] - 'a']--;
        }
        for (int c : freq)
            if (c != 0) return false;
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        
        for (int i = 1; i < words.size(); i++) {
            if (!isanagram(words[i], ans.back()))
                ans.push_back(words[i]);
        }
        return ans;
    }
};
