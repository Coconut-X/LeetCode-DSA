class Solution {
public:
    bool substr(string s, string sub) {

        if (s.size() < sub.size() || s == sub) return false;

        if (s.find(sub) != string::npos) 
        {
            return true;
        }

        return false; 
    }

    vector<string> stringMatching(vector<string>& words) {

        unordered_map<string, bool> m;

        vector<string> ans;
        for (auto s : words) {
            for (auto sub : words) {
                if (s != sub && substr(s, sub) and !m[sub]) { 
                    ans.push_back(sub);
                    m[sub]=true;
                }
            }
        }
        return ans;
    }
};
