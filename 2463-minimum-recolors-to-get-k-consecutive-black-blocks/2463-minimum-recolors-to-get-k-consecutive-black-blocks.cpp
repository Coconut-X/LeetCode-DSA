class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
        }

        int m = white;

        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i - k] == 'W') {
                white--;//[w,w,b,b,w,b] k=4, of at index i=4, remove w count at i=4 and increment count at index 4 to get W's count in next subarray 
            }
            if (blocks[i] == 'W') {
                white++;
            }
            m = min(m, white);
        }
        
        return m;
    }
};