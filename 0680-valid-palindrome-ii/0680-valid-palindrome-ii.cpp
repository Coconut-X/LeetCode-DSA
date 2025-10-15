class Solution {
public:

    bool ispalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return ispalindrome(s, left + 1, right) || ispalindrome(s, left, right - 1);
            }
        }

        return true;
    }
};
