class Solution {
public:
    int maxOperations(string s) {
        int total_operations = 0;
        int ones_count = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ones_count++;
            } else {

                if (i > 0 && s[i - 1] == '1') {
                    total_operations += ones_count;
                }
            }
        }

        return total_operations;
    }
};