class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ss = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                ss += " ";
                j++;
            }
            ss += s[i];
        }
        return ss;
    }
};
