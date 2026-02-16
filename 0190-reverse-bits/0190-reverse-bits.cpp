class Solution {
public:
    int reverseBits(int n) {
        
    int result = 0;
        for (int i = 0; i < 32; i++)
         {
            result <<= 1; // left shift result by 1 to make space for the next bit
            result |= (n & 1); // set the least significant bit of result to the current bit of n
            n >>= 1; // right shift n by 1 to get the next bit
        }
        return result;
        
    }
};