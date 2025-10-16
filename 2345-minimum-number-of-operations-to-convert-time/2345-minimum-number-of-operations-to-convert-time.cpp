class Solution {
public:
    int convertTime(string current, string correct) {
        int cur = stoi(current.substr(0,2)) * 60 + stoi(current.substr(3,2));
        int cor = stoi(correct.substr(0,2)) * 60 + stoi(correct.substr(3,2));
        int diff = cor - cur;

        int op = 0;
        op += diff / 60; diff %= 60;
        op += diff / 15; diff %= 15;
        op += diff / 5;  diff %= 5;
        op += diff;

        return op;
    }
};
