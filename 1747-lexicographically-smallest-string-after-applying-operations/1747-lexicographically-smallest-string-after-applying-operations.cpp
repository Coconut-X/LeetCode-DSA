struct tuple_hash {
    size_t operator()(const tuple<string,int,int>& t) const {
        auto h1 = hash<string>{}(get<0>(t));
        auto h2 = hash<int>{}(get<1>(t));
        auto h3 = hash<int>{}(get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Solution {
public:
    unordered_map<string,bool>mep;
    string brute(const string& s, int a, int b) {
        if(mep.count(s)) return s;
        mep[s] = true;
        string res = s;

        int len = s.size();
        int shift = b % len;
        string rot = s;
        if(shift > 0) {
            rot = s.substr(len - shift) + s.substr(0, len - shift);
            res = min(res, brute(rot, a, b));
        }

        string addA = s;
        for(int i = 1; i < len; i += 2) {
            addA[i] = (addA[i] - '0' + a) % 10 + '0';
        }
        if(addA != s) res = min(res, brute(addA, a, b));

        return res;
    }

    string findLexSmallestString(string s, int a, int b) {
        return brute(s, a, b);
    }
};
