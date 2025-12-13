class Solution {
public:
    bool isValidCode(const string& code) {
        if (code.empty())
            return false;
        for (char c : code) {
            if (!isalnum(c) && c != '_')
                return false;
        }
        return true;
    }
    bool isValidBusinessLine(const string& businessLine) {
        static const unordered_set<string> allowed = {"electronics", "grocery",
                                                      "pharmacy", "restaurant"};
        return allowed.count(businessLine) > 0;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_map<string, int> order = {{"electronics", 0},
                                            {"grocery", 1},
                                            {"pharmacy", 2},
                                            {"restaurant", 3}};

        vector<pair<string, string>> validCoupons;

        for (size_t i = 0; i < code.size(); i++) {
            if (isActive[i] && isValidCode(code[i]) &&
                isValidBusinessLine(businessLine[i])) {
                validCoupons.emplace_back(businessLine[i], code[i]);
            }
        }

        sort(validCoupons.begin(), validCoupons.end(),
             [&](const auto& a, const auto& b) {
                 if (order[a.first] != order[b.first])
                     return order[a.first] < order[b.first];
                 return a.second < b.second;
             });

        vector<string> result;
        for (const auto& p : validCoupons) {
            result.push_back(p.second);
        }
        return result;
    }
};