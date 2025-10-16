class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        //find first non 9 digit for max replacement
        string a = s;
        for(char c : s) {
            if(c != '9') {
                for(char &ch : a)
                    if(ch == c) ch = '9';
                break;
            }
        }

        //find first non 0 digit for min replacement
        string b = s;
        for(char c : s) {
            if(c != '0') {
                for(char &ch : b)
                    if(ch == c) ch = '0';
                break;
            }
        }

        return stoi(a) - stoi(b);
    }
};
