class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int sign = 1;
        bool seenDigit = false;

        while(index < s.size() && s[index] == ' ')
            index++;

        if(index < s.size() && (s[index] == '+' || s[index] == '-')){
            if(s[index] == '-') sign = -1;
            index++;
        }

        while(index < s.size() && s[index]=='0')
            index++;

        long long num = 0;

        while(index < s.size() && isdigit(s[index])){
            seenDigit = true;
            num = num * 10 + (s[index] - '0');
            if(num > INT_MAX) break;

            index++;
        }

        if(!seenDigit) return 0;

        num *= sign;

        if(num > INT_MAX) return INT_MAX;
        if(num < INT_MIN) return INT_MIN;

        return num;
    }
};
