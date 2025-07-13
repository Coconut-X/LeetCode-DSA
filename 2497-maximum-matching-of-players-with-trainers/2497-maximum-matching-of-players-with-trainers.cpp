class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        unordered_map<int, bool> mep;
        int count = 0;
        sort(trainers.begin(), trainers.end());

        for(int i = 0; i< players.size(); i++){
            
            auto it = lower_bound(trainers.begin(), trainers.end(), players[i]);
            
            if(it!=trainers.end()){
                count++;
                trainers.erase(it);
            }

        }
        
        return count;
    }
};