class Solution {
public:
    int binaryGap(int n) {
        if((n > 0) && ((n & (n - 1)) == 0)) return 0; //pow of 2
        const int n_bits = std::numeric_limits<int>::digits + 1; //+1 for sign bit if signnd
        string bs = bitset<n_bits>(n).to_string();
        int left = 0; int right = 0;
        int longest = 0;
        while(left < bs.size() and right < bs.size()){

            while(left < bs.size() and bs[left] == '0')left++;
            if(left == bs.size()) break;
            right = left+1;

            while(right < bs.size() and bs[right] == '0') right++;
            if(right == bs.size()) break;
            longest = max(longest, right - left);
            left++;
        }
        return longest;
    }
};