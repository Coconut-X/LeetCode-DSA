class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int fs = fruits.size();
        int placed = fs;
        for(int i = 0;i < fs; i++){
            for(int j = 0; j < fs; j++){
                if(baskets[j]>=fruits[i]){
                    placed--;
                    baskets[j] = 0;
                    break;
                }
            }
        }
        
        return placed;
    }
};