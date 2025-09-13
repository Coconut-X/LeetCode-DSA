class Solution {
public:
    int maxFreqSum(std::string s) {
        std::unordered_map<char, int> v, C;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                v[c]++;
            } else {
                C[c]++;
            }
        }

        int max_v_freq = 0;
        if (!v.empty()) {
            auto mv = std::max_element(v.begin(), v.end(),
                [](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
                    return p1.second < p2.second;
                });
            max_v_freq = mv->second;
        }

        int max_c_freq = 0;
        if (!C.empty()) {
            auto mc = std::max_element(C.begin(), C.end(),
                [](const std::pair<char, int>& p1, const std::pair<char, int>& p2) {
                    return p1.second < p2.second;
                });
            max_c_freq = mc->second;
        }

        return max_v_freq + max_c_freq;
    }
};