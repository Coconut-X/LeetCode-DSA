class Solution {
public:

    int maxDistance(vector<int>& colors) {
        int m = 0;
        for(int i = 0; i < colors.size(); i++){
            for(int j = colors.size() - 1; j > i; j--){
                if(colors[i]!=colors[j]){
                    m = max(m, j-i);
                    break;
                }
            }
        }
        return m;
    }
};