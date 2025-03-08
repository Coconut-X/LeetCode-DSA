class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int m = INT_MAX;
        for (int i = 0; i <= blocks.size() - k; i++) {
            
            int count = 0;
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') count++;
            }
            m = min(m, count);
        }
        return m;
    }
};